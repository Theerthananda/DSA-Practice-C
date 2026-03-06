const input=document.getElementById("cmd");
const display=document.getElementById("display");
const history=document.getElementById("history");
const commandItems=document.querySelectorAll(".command-item");

let commandHistory=[];

const CONFIG={
ownerName:"Theerthananda",
ownerEmail:"yourgmail@gmail.com",
// Optional: set this to your backend endpoint to make visitor stats/guestbook global + verifiable.
// Example: "https://your-api.example.com/portfolio"
apiUrl:""
};

const STORAGE_KEYS={
visitsTotal:"tt_portfolio_visits_total",
guestbook:"tt_portfolio_guestbook",
connects:"tt_portfolio_connects"
};

// Set current year
document.getElementById("year").textContent=new Date().getFullYear();

function escapeHtml(str){
return String(str)
.replaceAll("&","&amp;")
.replaceAll("<","&lt;")
.replaceAll(">","&gt;")
.replaceAll("\"","&quot;")
.replaceAll("'","&#039;");
}

function isValidName(name){
// Allows letters, spaces, dots. Min 2 words preferred but not forced.
const cleaned=name.trim().replace(/\s+/g," ");
if(cleaned.length<2||cleaned.length>60)return false;
return /^[A-Za-z.\s]+$/.test(cleaned);
}

function isValidEmail(email){
const e=email.trim();
if(e.length<6||e.length>120)return false;
return /^[^\s@]+@[^\s@]+\.[^\s@]{2,}$/.test(e);
}

function getGuestbook(){
try{
const raw=localStorage.getItem(STORAGE_KEYS.guestbook);
if(!raw)return [];
const parsed=JSON.parse(raw);
return Array.isArray(parsed)?parsed:[];
}catch{
return [];
}
}

function setGuestbook(entries){
localStorage.setItem(STORAGE_KEYS.guestbook,JSON.stringify(entries.slice(0,50)));
}

function addGuestbookEntry(name){
const cleaned=name.trim().replace(/\s+/g," ");
const entries=getGuestbook();
// de-dupe by normalized name
const key=cleaned.toLowerCase();
const exists=entries.some(e=>(e?.name||"").toLowerCase()===key);
if(exists)return false;
entries.unshift({name:cleaned,ts:Date.now()});
setGuestbook(entries);
return true;
}

function getConnects(){
try{
const raw=localStorage.getItem(STORAGE_KEYS.connects);
if(!raw)return [];
const parsed=JSON.parse(raw);
return Array.isArray(parsed)?parsed:[];
}catch{return [];}
}

function addConnectSubmission(data){
const entries=getConnects();
entries.unshift({...data,ts:Date.now()});
localStorage.setItem(STORAGE_KEYS.connects,JSON.stringify(entries.slice(0,100)));
}

function incrementVisitCounter(){
// Count once per tab session
if(sessionStorage.getItem("tt_visit_counted")==="1")return;
sessionStorage.setItem("tt_visit_counted","1");

const current=Number(localStorage.getItem(STORAGE_KEYS.visitsTotal)||"0");
localStorage.setItem(STORAGE_KEYS.visitsTotal,String(current+1));
}

incrementVisitCounter();

// Particle system
const canvas=document.getElementById("particles");
const ctx=canvas.getContext("2d");
canvas.width=window.innerWidth;
canvas.height=window.innerHeight;

const particles=[];
const particleCount=36;

class Particle{
constructor(){
this.x=Math.random()*canvas.width;
this.y=Math.random()*canvas.height;
this.size=Math.random()*2+0.8;
this.speedX=Math.random()*1.2-0.6;
this.speedY=Math.random()*1.2-0.6;
this.opacity=Math.random()*0.3+0.1;
this.color=`hsl(217,${Math.random()*30+60}%,${Math.random()*20+60}%)`;
}

update(){
this.x+=this.speedX;
this.y+=this.speedY;

if(this.x>canvas.width)this.x=0;
if(this.x<0)this.x=canvas.width;
if(this.y>canvas.height)this.y=0;
if(this.y<0)this.y=canvas.height;
}

draw(){
ctx.beginPath();
ctx.arc(this.x,this.y,this.size,0,Math.PI*2);
ctx.fillStyle=this.color;
ctx.globalAlpha=this.opacity;
ctx.fill();
ctx.globalAlpha=1;
}
}

for(let i=0;i<particleCount;i++){
particles.push(new Particle());
}

function animateParticles(){
ctx.clearRect(0,0,canvas.width,canvas.height);

particles.forEach(particle=>{
particle.update();
particle.draw();
});

// Connect nearby particles
for(let i=0;i<particles.length;i++){
for(let j=i+1;j<particles.length;j++){
const dx=particles[i].x-particles[j].x;
const dy=particles[i].y-particles[j].y;
const distance=Math.sqrt(dx*dx+dy*dy);

if(distance<120){
ctx.beginPath();
ctx.strokeStyle=`rgba(59,130,246,${0.15*(1-distance/120)})`;
ctx.lineWidth=0.5;
ctx.moveTo(particles[i].x,particles[i].y);
ctx.lineTo(particles[j].x,particles[j].y);
ctx.stroke();
}
}
}

requestAnimationFrame(animateParticles);
}

animateParticles();

window.addEventListener("resize",()=>{
canvas.width=window.innerWidth;
canvas.height=window.innerHeight;
});

// Command click handlers
commandItems.forEach(item=>{
item.addEventListener("click",()=>{
const cmd=item.getAttribute("data-cmd");
input.value=cmd;
runCommand(cmd);
input.value="";
});
});

// Terminal input
input.addEventListener("keydown",function(e){
if(e.key==="Enter"){
const cmd=input.value.trim().toLowerCase();
if(cmd){
addToHistory(cmd);
runCommand(cmd);
input.value="";
}
}
else if(e.key==="ArrowUp"){
if(commandHistory.length>0){
const lastCmd=commandHistory[commandHistory.length-1];
input.value=lastCmd;
}
e.preventDefault();
}
});

function addToHistory(cmd){
commandHistory.push(cmd);
if(commandHistory.length>10)commandHistory.shift();

const historyItem=document.createElement("div");
historyItem.className="history-item";
historyItem.innerHTML=`<span class="prompt">$</span> ${cmd}`;
history.appendChild(historyItem);

// Keep only last 5 visible
const historyItems=history.querySelectorAll(".history-item");
if(historyItems.length>5){
historyItems[0].remove();
}

// Scroll to bottom
history.scrollTop=history.scrollHeight;
}

function createCard(content,className=""){
const card=document.createElement("div");
card.className=`card ${className}`;
card.innerHTML=content;
return card;
}

function animateCards(){
const cards=display.querySelectorAll(".card");
cards.forEach((card,index)=>{
card.style.animationDelay=`${index*0.1}s`;
});
}

function setDisplay(nodeOrHtml){
display.innerHTML="";
if(typeof nodeOrHtml==="string"){
display.innerHTML=nodeOrHtml;
return;
}
display.appendChild(nodeOrHtml);
}

function renderNotice(title,body){
return createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:1.8em;margin-bottom:12px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">${escapeHtml(title)}</h2>
<p style="margin:0;color:rgba(228,228,231,0.75);line-height:1.7;font-size:0.98em;">${body}</p>
`,"big");
}

function runCommand(cmd){
display.innerHTML="";

if(cmd==="help"){
const commands=[
{name:"about",desc:"Quick intro and overview"},
{name:"education",desc:"Academic background"},
{name:"skills",desc:"Technical skills"},
{name:"projects",desc:"Featured and active work"},
{name:"now",desc:"What I'm working on currently"},
{name:"connect",desc:"Send your details to connect with me"},
{name:"guestbook",desc:"Leave your name (visitor log)"},
{name:"stats",desc:"View local visitor stats"},
{name:"contact",desc:"Social links and email"},
{name:"clear",desc:"Reset to welcome screen"}
];

commands.forEach(cmd=>{
const card=createCard(`
<div style="display:flex;justify-content:space-between;align-items:center;">
<div style="flex:1;">
<h3 style="margin:0 0 6px 0;color:#ffffff;font-size:1.1em;font-weight:600;">${cmd.name}</h3>
<p style="margin:0;color:rgba(228,228,231,0.6);font-size:0.9em;line-height:1.4;">${cmd.desc}</p>
</div>
<span style="color:#3b82f6;font-size:1.2em;margin-left:16px;opacity:0.6;">→</span>
</div>
`);
display.appendChild(card);
});
animateCards();
}

else if(cmd==="about"){
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:16px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Theerthananda</h2>
<p style="margin:0 0 18px 0;color:rgba(228,228,231,0.75);font-size:1em;line-height:1.7;">
MSc Computer Science student with a strong interest in problem-solving, backend fundamentals, and building clean, reliable software.
</p>
<div style="display:grid;grid-template-columns:1fr;gap:10px;font-size:1.02em;line-height:1.6;color:rgba(228,228,231,0.9);">
<div style="display:flex;align-items:flex-start;gap:12px;"><span style="color:#3b82f6;font-size:0.9em;line-height:1.6;">●</span><div><b style="color:#ffffff;font-weight:600;">Focus</b><div style="color:rgba(228,228,231,0.75);">DSA · SQL · Web Development · Java · C# · .NET</div></div></div>
<div style="display:flex;align-items:flex-start;gap:12px;"><span style="color:#3b82f6;font-size:0.9em;line-height:1.6;">●</span><div><b style="color:#ffffff;font-weight:600;">Education</b><div style="color:rgba(228,228,231,0.75);">MSc CS @ JSS College, Mysore · BSc completed @ SDM College, Ujire</div></div></div>
<div style="display:flex;align-items:flex-start;gap:12px;"><span style="color:#3b82f6;font-size:0.9em;line-height:1.6;">●</span><div><b style="color:#ffffff;font-weight:600;">Featured</b><div style="color:rgba(228,228,231,0.75);">Event Ops Coordination System</div></div></div>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="education"){
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:16px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Education</h2>
<div style="display:grid;gap:14px;">
  <div style="padding:14px 16px;border:1px solid rgba(255,255,255,0.06);border-radius:12px;background:rgba(255,255,255,0.02);">
    <div style="display:flex;justify-content:space-between;gap:12px;flex-wrap:wrap;">
      <div style="font-weight:600;color:#ffffff;">MSc Computer Science</div>
      <div style="color:rgba(228,228,231,0.6);font-size:0.9em;">JSS College, Mysore</div>
    </div>
    <div style="margin-top:8px;color:rgba(228,228,231,0.75);line-height:1.6;font-size:0.95em;">
      Building strong CS fundamentals with focus on DSA, databases, and practical development.
    </div>
  </div>
  <div style="padding:14px 16px;border:1px solid rgba(255,255,255,0.06);border-radius:12px;background:rgba(255,255,255,0.02);">
    <div style="display:flex;justify-content:space-between;gap:12px;flex-wrap:wrap;">
      <div style="font-weight:600;color:#ffffff;">BSc (Completed)</div>
      <div style="color:rgba(228,228,231,0.6);font-size:0.9em;">SDM College, Ujire</div>
    </div>
    <div style="margin-top:8px;color:rgba(228,228,231,0.75);line-height:1.6;font-size:0.95em;">
      Built a foundation in computing and problem-solving.
    </div>
  </div>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="skills"){
const skills=[
{name:"Data Structures & Algorithms (DSA)",level:86,color:"#3b82f6"},
{name:"SQL",level:82,color:"#06b6d4"},
{name:"Web Development (HTML/CSS/JS)",level:80,color:"#8b5cf6"},
{name:"Java",level:78,color:"#3b82f6"},
{name:"C# & .NET",level:76,color:"#10b981"}
];

skills.forEach(skill=>{
const card=createCard(`
<h3 style="margin:0 0 12px 0;color:#ffffff;font-size:1.1em;font-weight:600;">${skill.name}</h3>
<div style="background:rgba(255,255,255,0.05);border-radius:6px;height:6px;overflow:hidden;position:relative;margin-bottom:8px;">
<div style="background:${skill.color};height:100%;width:${skill.level}%;border-radius:6px;transition:width 0.8s ease-out;"></div>
</div>
<p style="margin:0;font-size:0.85em;color:rgba(228,228,231,0.6);">${skill.level}% proficiency</p>
`);
display.appendChild(card);
});
animateCards();
setTimeout(()=>{
const bars=display.querySelectorAll(".card div div");
bars.forEach(bar=>bar.style.width=bar.style.width);
},100);
}

else if(cmd==="projects"){
const projects=[
{
name:"Event Ops Coordination System",
desc:"System to manage event operations: planning, task assignment, coordination, and tracking.",
tech:["C#",".NET","SQL"],
color:"#3b82f6"
},
{
name:"Interactive Terminal Portfolio",
desc:"A command-driven portfolio interface with clean UI and structured sections.",
tech:["HTML","CSS","JavaScript"],
color:"#8b5cf6"
},
{
name:"Running Projects (In Progress)",
desc:"A set of projects I’m actively building and improving alongside my academics.",
tech:["DSA Practice","Web","SQL"],
color:"#06b6d4"
}
];

projects.forEach(project=>{
const card=createCard(`
<h3 style="margin:0 0 12px 0;color:#ffffff;font-size:1.2em;font-weight:600;font-family:'Inter',sans-serif;">${project.name}</h3>
<p style="margin:0 0 16px 0;color:rgba(228,228,231,0.8);line-height:1.6;font-size:0.95em;">${project.desc}</p>
<div style="display:flex;flex-wrap:wrap;gap:6px;">
${project.tech.map(t=>`<span style="background:rgba(255,255,255,0.03);padding:4px 10px;border-radius:6px;font-size:0.8em;border:1px solid ${project.color}33;color:${project.color};font-weight:600;">${t}</span>`).join("")}
</div>
`);
display.appendChild(card);
});
animateCards();
}

else if(cmd==="now"){
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:16px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Now</h2>
<p style="margin:0 0 18px 0;color:rgba(228,228,231,0.75);line-height:1.7;">
Currently focused on building strong fundamentals and shipping projects that demonstrate real-world coordination and backend skills.
</p>
<div style="display:grid;gap:10px;">
  <div style="padding:14px 16px;border:1px solid rgba(255,255,255,0.06);border-radius:12px;background:rgba(255,255,255,0.02);">
    <div style="display:flex;justify-content:space-between;gap:12px;flex-wrap:wrap;">
      <div style="font-weight:600;color:#ffffff;">Event Ops Coordination System</div>
      <div style="color:rgba(59,130,246,0.9);font-size:0.85em;font-weight:600;">Active</div>
    </div>
    <div style="margin-top:8px;color:rgba(228,228,231,0.75);line-height:1.6;font-size:0.95em;">
      Improving workflows, data modeling, and clean UI patterns.
    </div>
  </div>
  <div style="padding:14px 16px;border:1px solid rgba(255,255,255,0.06);border-radius:12px;background:rgba(255,255,255,0.02);">
    <div style="display:flex;justify-content:space-between;gap:12px;flex-wrap:wrap;">
      <div style="font-weight:600;color:#ffffff;">DSA + SQL Practice</div>
      <div style="color:rgba(16,185,129,0.9);font-size:0.85em;font-weight:600;">Daily</div>
    </div>
    <div style="margin-top:8px;color:rgba(228,228,231,0.75);line-height:1.6;font-size:0.95em;">
      Focus on patterns, complexity, and writing readable solutions.
    </div>
  </div>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="connect"){
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:10px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Connect with me</h2>
<p style="margin:0 0 18px 0;color:rgba(228,228,231,0.65);line-height:1.7;font-size:0.95em;">
Fill this form and click <b>Send</b>. By default it opens your email client (professional and reliable for a static website).
</p>

<form id="connectForm" class="connect-form" novalidate>
  <div class="form-grid">
    <div class="field">
      <label class="label" for="cName">Full name</label>
      <input class="control" id="cName" name="name" placeholder="Your full name" required>
      <div class="hint" id="cNameHint">Use your real name (letters only).</div>
    </div>
    <div class="field">
      <label class="label" for="cEmail">Email</label>
      <input class="control" id="cEmail" name="email" placeholder="you@example.com" required>
      <div class="hint" id="cEmailHint">I’ll reply to this email.</div>
    </div>
  </div>

  <div class="field">
    <label class="label" for="cPurpose">Purpose</label>
    <input class="control" id="cPurpose" name="purpose" placeholder="Hiring / Collaboration / Question / Other">
  </div>

  <div class="field">
    <label class="label" for="cMessage">Message</label>
    <textarea class="control textarea" id="cMessage" name="message" rows="5" placeholder="Write a short message..."></textarea>
  </div>

  <label class="check">
    <input type="checkbox" id="cGuestbook" checked>
    <span>Add my name to the guestbook (local)</span>
  </label>

  <div class="actions">
    <button class="btn primary" type="submit">Send</button>
    <button class="btn" type="button" id="cClear">Clear</button>
    <span class="status" id="cStatus"></span>
  </div>
</form>

<div style="margin-top:16px;padding-top:14px;border-top:1px solid rgba(255,255,255,0.06);color:rgba(228,228,231,0.6);font-size:0.9em;line-height:1.6;">
<b style="color:#ffffff;">Note on verification:</b> a static website cannot truly verify real identities. I added strong validation, and you can enable real verification later by connecting a backend.
</div>
`,"big");

display.appendChild(card);
animateCards();

const form=document.getElementById("connectForm");
const status=document.getElementById("cStatus");
const nameEl=document.getElementById("cName");
const emailEl=document.getElementById("cEmail");
const purposeEl=document.getElementById("cPurpose");
const msgEl=document.getElementById("cMessage");
const gbEl=document.getElementById("cGuestbook");
const clearBtn=document.getElementById("cClear");

function setStatus(text,type=""){
status.textContent=text;
status.className=`status ${type}`;
}

clearBtn.addEventListener("click",()=>{
nameEl.value=""; emailEl.value=""; purposeEl.value=""; msgEl.value="";
gbEl.checked=true;
setStatus("");
});

form.addEventListener("submit",async(e)=>{
e.preventDefault();
const name=nameEl.value.trim().replace(/\s+/g," ");
const email=emailEl.value.trim();
const purpose=purposeEl.value.trim();
const message=msgEl.value.trim();

if(!isValidName(name)){
setStatus("Please enter a valid name (letters/spaces only).","error");
nameEl.focus();
return;
}
if(!isValidEmail(email)){
setStatus("Please enter a valid email address.","error");
emailEl.focus();
return;
}

if(gbEl.checked){
addGuestbookEntry(name);
}

// Store connect submission for admin dashboard
addConnectSubmission({name,email,purpose,message});

setStatus("Preparing message...","");

const subject=`Portfolio connect request — ${name}`;
const body=[
`Name: ${name}`,
`Email: ${email}`,
purpose?`Purpose: ${purpose}`:"",
message?`Message: ${message}`:"",
``,
`(Sent from Theerthananda's portfolio connect form)`
].filter(Boolean).join("\n");

// Backend-ready hook (optional)
if(CONFIG.apiUrl){
try{
setStatus("Sending...","");
await fetch(CONFIG.apiUrl,{
method:"POST",
headers:{"Content-Type":"application/json"},
body:JSON.stringify({type:"connect",name,email,purpose,message,ts:Date.now()})
});
setStatus("Sent successfully. Thank you!","ok");
}catch{
setStatus("Could not send to server. Opening email client instead...","warn");
window.location.href=`mailto:${encodeURIComponent(CONFIG.ownerEmail)}?subject=${encodeURIComponent(subject)}&body=${encodeURIComponent(body)}`;
}
return;
}

// Default static-site behavior: mailto
window.location.href=`mailto:${encodeURIComponent(CONFIG.ownerEmail)}?subject=${encodeURIComponent(subject)}&body=${encodeURIComponent(body)}`;
setStatus("Opened your email app. Please press Send in your email client.","ok");
});
}

else if(cmd==="guestbook"){
const entries=getGuestbook();
const list=entries.length
? entries.map(e=>`<div class="gb-row"><span class="gb-dot"></span><span class="gb-name">${escapeHtml(e.name)}</span><span class="gb-time">${new Date(e.ts).toLocaleDateString()}</span></div>`).join("")
: `<div style="color:rgba(228,228,231,0.65);line-height:1.7;">No entries yet. Type <b style="color:#ffffff;">connect</b> and tick “Add my name to the guestbook”.</div>`;

const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:10px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Guestbook</h2>
<p style="margin:0 0 16px 0;color:rgba(228,228,231,0.65);line-height:1.7;font-size:0.95em;">
Visitor names saved on this device (local). For a real public guestbook + verification, connect a backend.
</p>
<div class="gb">${list}</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="stats"){
const total=Number(localStorage.getItem(STORAGE_KEYS.visitsTotal)||"0");
const gbCount=getGuestbook().length;
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Inter',sans-serif;font-size:2em;margin-bottom:16px;color:#ffffff;font-weight:600;letter-spacing:-0.5px;">Visitor stats</h2>
<div class="stat-grid">
  <div class="stat">
    <div class="stat-label">Visits (local)</div>
    <div class="stat-value">${total}</div>
  </div>
  <div class="stat">
    <div class="stat-label">Guestbook entries (local)</div>
    <div class="stat-value">${gbCount}</div>
  </div>
</div>
<div style="margin-top:16px;color:rgba(228,228,231,0.65);line-height:1.7;font-size:0.95em;">
<b style="color:#ffffff;">Important:</b> These counts are stored in <b>your browser</b>. To make it real-time across all visitors (and support verification), you need a backend (I already added a hook via <code style="color:#ffffff;">CONFIG.apiUrl</code>).
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="contact"){
const card=createCard(`
<div style="text-align:center;">
<h3 style="font-family:'Inter',sans-serif;font-size:1.6em;margin-bottom:10px;color:#ffffff;font-weight:600;">Contact</h3>
<p style="margin:0 0 22px 0;color:rgba(228,228,231,0.6);font-size:0.95em;line-height:1.6;">Replace the placeholder links in <b>script.js</b> with your real profiles.</p>
<div style="font-size:1em;line-height:2.2;">
<p style="margin:16px 0;">
<span style="color:#3b82f6;margin-right:12px;">Email</span>
<a href="mailto:yourgmail@gmail.com" style="color:#3b82f6;text-decoration:none;transition:color 0.2s;font-weight:600;">yourgmail@gmail.com</a>
</p>
<p style="margin:16px 0;">
<span style="color:#3b82f6;margin-right:12px;">LinkedIn</span>
<a href="https://www.linkedin.com/in/your-linkedin/" target="_blank" rel="noreferrer" style="color:#3b82f6;text-decoration:none;transition:color 0.2s;font-weight:600;">linkedin.com/in/your-linkedin</a>
</p>
<p style="margin:16px 0;">
<span style="color:#3b82f6;margin-right:12px;">Instagram</span>
<a href="https://www.instagram.com/your-instagram/" target="_blank" rel="noreferrer" style="color:#3b82f6;text-decoration:none;transition:color 0.2s;font-weight:600;">instagram.com/your-instagram</a>
</p>
</div>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="clear"){
display.innerHTML=`
<div class="card big welcome-card">
<h2>Welcome</h2>
<p class="welcome-text">Type <b class="highlight">help</b> in the terminal to explore available commands</p>
<p class="welcome-subtext">Navigate through my portfolio using command-line interface</p>
</div>
`;
animateCards();
}

else{
const card=createCard(`
<div style="text-align:center;">
<span style="color:#ef4444;font-size:1.8em;display:block;margin-bottom:12px;">⚠</span>
<h3 style="margin:0 0 8px 0;color:#ef4444;font-size:1.2em;font-weight:600;">Command not found</h3>
<p style="color:rgba(228,228,231,0.7);font-size:0.95em;">Type <span style="color:#3b82f6;font-weight:500;">help</span> to see available commands</p>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

// Focus input after command
setTimeout(()=>input.focus(),100);
}

// Auto-focus input on load
input.focus();