const STORAGE_KEYS={
visitsTotal:"tt_portfolio_visits_total",
guestbook:"tt_portfolio_guestbook",
connects:"tt_portfolio_connects",
adminPassword:"tt_admin_password"
};

const DEFAULT_PASSWORD="theerthananda2024";

// Initialize password if not set
if(!localStorage.getItem(STORAGE_KEYS.adminPassword)){
localStorage.setItem(STORAGE_KEYS.adminPassword,DEFAULT_PASSWORD);
}

const loginScreen=document.getElementById("loginScreen");
const dashboardScreen=document.getElementById("dashboardScreen");
const passwordInput=document.getElementById("adminPassword");
const loginBtn=document.getElementById("loginBtn");
const logoutBtn=document.getElementById("logoutBtn");
const loginError=document.getElementById("loginError");

// Check if already logged in
if(sessionStorage.getItem("tt_admin_logged_in")==="true"){
showDashboard();
}

// Login
loginBtn.addEventListener("click",()=>{
const password=passwordInput.value.trim();
const storedPassword=localStorage.getItem(STORAGE_KEYS.adminPassword);

if(password===storedPassword){
sessionStorage.setItem("tt_admin_logged_in","true");
showDashboard();
loginError.textContent="";
passwordInput.value="";
}else{
loginError.textContent="Incorrect password";
passwordInput.value="";
passwordInput.focus();
}
});

passwordInput.addEventListener("keydown",(e)=>{
if(e.key==="Enter"){
loginBtn.click();
}
});

// Logout
logoutBtn.addEventListener("click",()=>{
sessionStorage.removeItem("tt_admin_logged_in");
showLogin();
});

function showLogin(){
loginScreen.classList.remove("hidden");
dashboardScreen.classList.add("hidden");
}

function showDashboard(){
loginScreen.classList.add("hidden");
dashboardScreen.classList.remove("hidden");
loadDashboardData();
}

// Tab switching
const tabBtns=document.querySelectorAll(".tab-btn");
const tabContents=document.querySelectorAll(".tab-content");

tabBtns.forEach(btn=>{
btn.addEventListener("click",()=>{
const targetTab=btn.getAttribute("data-tab");

tabBtns.forEach(b=>b.classList.remove("active"));
tabContents.forEach(c=>c.classList.remove("active"));

btn.classList.add("active");
document.getElementById(`${targetTab}Tab`).classList.add("active");
});
});

// Load data
function loadDashboardData(){
// Get data from localStorage (same keys as main portfolio)
const visitsTotal=Number(localStorage.getItem(STORAGE_KEYS.visitsTotal)||"0");
const guestbookRaw=localStorage.getItem(STORAGE_KEYS.guestbook);
const connectsRaw=localStorage.getItem(STORAGE_KEYS.connects);

let guestbook=[];
let connects=[];

try{
if(guestbookRaw)guestbook=JSON.parse(guestbookRaw);
if(connectsRaw)connects=JSON.parse(connectsRaw);
}catch(e){
console.error("Error parsing data:",e);
}

// Update stats
document.getElementById("totalVisits").textContent=visitsTotal.toLocaleString();
document.getElementById("guestbookCount").textContent=guestbook.length;
document.getElementById("connectsCount").textContent=connects.length;

const lastUpdate=new Date();
document.getElementById("lastUpdate").textContent=lastUpdate.toLocaleTimeString();

// Load connects table
loadConnectsTable(connects);

// Load guestbook table
loadGuestbookTable(guestbook);
}

function loadConnectsTable(connects){
const tbody=document.getElementById("connectsTableBody");

if(connects.length===0){
tbody.innerHTML='<tr><td colspan="5" class="empty-state">No connect requests yet</td></tr>';
return;
}

tbody.innerHTML=connects
.sort((a,b)=>b.ts-a.ts)
.map(c=>{
const date=new Date(c.ts);
const dateStr=date.toLocaleString();
const name=escapeHtml(c.name||"");
const email=escapeHtml(c.email||"");
const purpose=escapeHtml(c.purpose||"-");
const message=escapeHtml((c.message||"").substring(0,100))+(c.message&&c.message.length>100?"...":"");

return `
<tr>
<td style="white-space:nowrap;color:rgba(228,228,231,0.7);font-size:0.9em;">${dateStr}</td>
<td style="font-weight:500;color:#ffffff;">${name}</td>
<td><a href="mailto:${email}" style="color:#3b82f6;text-decoration:none;">${email}</a></td>
<td>${purpose}</td>
<td style="max-width:300px;overflow:hidden;text-overflow:ellipsis;" title="${escapeHtml(c.message||"")}">${message}</td>
</tr>
`;
}).join("");
}

function loadGuestbookTable(guestbook){
const tbody=document.getElementById("guestbookTableBody");

if(guestbook.length===0){
tbody.innerHTML='<tr><td colspan="3" class="empty-state">No guestbook entries yet</td></tr>';
return;
}

tbody.innerHTML=guestbook
.sort((a,b)=>b.ts-a.ts)
.map(g=>{
const date=new Date(g.ts);
const dateStr=date.toLocaleString();
const name=escapeHtml(g.name||"");

return `
<tr>
<td style="white-space:nowrap;color:rgba(228,228,231,0.7);font-size:0.9em;">${dateStr}</td>
<td style="font-weight:500;color:#ffffff;">${name}</td>
<td><button class="btn-secondary" onclick="deleteGuestbookEntry('${g.ts}')" style="font-size:0.85em;padding:4px 12px;">Delete</button></td>
</tr>
`;
}).join("");
}

function deleteGuestbookEntry(ts){
if(!confirm("Delete this guestbook entry?"))return;

const guestbookRaw=localStorage.getItem(STORAGE_KEYS.guestbook);
if(!guestbookRaw)return;

try{
const guestbook=JSON.parse(guestbookRaw);
const filtered=guestbook.filter(g=>String(g.ts)!==String(ts));
localStorage.setItem(STORAGE_KEYS.guestbook,JSON.stringify(filtered));
loadDashboardData();
}catch(e){
console.error("Error deleting entry:",e);
}
}

// Export functions
document.getElementById("exportConnects").addEventListener("click",()=>{
const connectsRaw=localStorage.getItem(STORAGE_KEYS.connects);
if(!connectsRaw){
alert("No data to export");
return;
}

try{
const connects=JSON.parse(connectsRaw);
const csv=[
["Date & Time","Name","Email","Purpose","Message"],
...connects.map(c=>{
const date=new Date(c.ts).toLocaleString();
return [date,c.name||"",c.email||"",c.purpose||"",(c.message||"").replace(/"/g,'""')];
})
].map(row=>row.map(cell=>`"${cell}"`).join(",")).join("\n");

downloadCSV(csv,"connects_export.csv");
}catch(e){
alert("Error exporting data");
console.error(e);
}
});

document.getElementById("exportGuestbook").addEventListener("click",()=>{
const guestbookRaw=localStorage.getItem(STORAGE_KEYS.guestbook);
if(!guestbookRaw){
alert("No data to export");
return;
}

try{
const guestbook=JSON.parse(guestbookRaw);
const csv=[
["Date & Time","Name"],
...guestbook.map(g=>{
const date=new Date(g.ts).toLocaleString();
return [date,g.name||""];
})
].map(row=>row.map(cell=>`"${cell}"`).join(",")).join("\n");

downloadCSV(csv,"guestbook_export.csv");
}catch(e){
alert("Error exporting data");
console.error(e);
}
});

function downloadCSV(content,filename){
const blob=new Blob([content],{type:"text/csv;charset=utf-8;"});
const link=document.createElement("a");
const url=URL.createObjectURL(blob);
link.setAttribute("href",url);
link.setAttribute("download",filename);
link.style.visibility="hidden";
document.body.appendChild(link);
link.click();
document.body.removeChild(link);
}

function escapeHtml(str){
return String(str)
.replaceAll("&","&amp;")
.replaceAll("<","&lt;")
.replaceAll(">","&gt;")
.replaceAll('"',"&quot;")
.replaceAll("'","&#039;");
}

// Auto-refresh every 30 seconds
setInterval(()=>{
if(!dashboardScreen.classList.contains("hidden")){
loadDashboardData();
}
},30000);