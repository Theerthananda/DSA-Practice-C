const input=document.getElementById("cmd");
const display=document.getElementById("display");
const history=document.getElementById("history");
const commandItems=document.querySelectorAll(".command-item");

let commandHistory=[];

// Set current year
document.getElementById("year").textContent=new Date().getFullYear();

// Particle system
const canvas=document.getElementById("particles");
const ctx=canvas.getContext("2d");
canvas.width=window.innerWidth;
canvas.height=window.innerHeight;

const particles=[];
const particleCount=50;

class Particle{
constructor(){
this.x=Math.random()*canvas.width;
this.y=Math.random()*canvas.height;
this.size=Math.random()*3+1;
this.speedX=Math.random()*2-1;
this.speedY=Math.random()*2-1;
this.opacity=Math.random()*0.5+0.2;
this.color=`hsl(${Math.random()*60+180},100%,70%)`;
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

if(distance<150){
ctx.beginPath();
ctx.strokeStyle=`rgba(0,240,255,${0.2*(1-distance/150)})`;
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

function runCommand(cmd){
display.innerHTML="";

if(cmd==="help"){
const commands=[
{name:"about",desc:"Learn about me"},
{name:"skills",desc:"View my skills"},
{name:"projects",desc:"See my projects"},
{name:"contact",desc:"Get in touch"},
{name:"clear",desc:"Clear the display"}
];

commands.forEach(cmd=>{
const card=createCard(`
<div style="display:flex;justify-content:space-between;align-items:center;">
<div>
<h3 style="margin:0 0 5px 0;color:#00f0ff;">${cmd.name}</h3>
<p style="margin:0;color:rgba(255,255,255,0.7);font-size:0.9em;">${cmd.desc}</p>
</div>
<span style="color:#00f0ff;font-size:1.5em;">→</span>
</div>
`);
display.appendChild(card);
});
animateCards();
}

else if(cmd==="about"){
const card=createCard(`
<div class="card-glow"></div>
<h2 style="font-family:'Orbitron',sans-serif;font-size:2.2em;margin-bottom:15px;background:linear-gradient(135deg,#00f0ff,#ff00ff);-webkit-background-clip:text;-webkit-text-fill-color:transparent;background-clip:text;">Your Name</h2>
<div style="font-size:1.2em;line-height:1.8;">
<p style="margin:10px 0;"><span style="color:#00f0ff;">●</span> MSc Computer Science Student</p>
<p style="margin:10px 0;"><span style="color:#00f0ff;">●</span> Flutter Developer</p>
<p style="margin:10px 0;"><span style="color:#00f0ff;">●</span> Passionate about creating amazing experiences</p>
</div>
`,"big");
display.appendChild(card);
animateCards();
}

else if(cmd==="skills"){
const skills=[
{name:"C Programming",level:90,color:"#00f0ff"},
{name:"Flutter",level:85,color:"#00ff88"},
{name:"Node.js",level:80,color:"#ff00ff"},
{name:"MySQL",level:75,color:"#ffbd2e"},
{name:"JavaScript",level:88,color:"#00f0ff"},
{name:"HTML/CSS",level:92,color:"#00ff88"}
];

skills.forEach(skill=>{
const card=createCard(`
<h3 style="margin:0 0 10px 0;color:${skill.color};font-size:1.3em;">${skill.name}</h3>
<div style="background:rgba(255,255,255,0.1);border-radius:10px;height:8px;overflow:hidden;position:relative;">
<div style="background:linear-gradient(90deg,${skill.color},${skill.color}88);height:100%;width:${skill.level}%;border-radius:10px;transition:width 1s ease-out;box-shadow:0 0 10px ${skill.color};"></div>
</div>
<p style="margin:5px 0 0 0;font-size:0.9em;color:rgba(255,255,255,0.7);">${skill.level}%</p>
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
name:"Go Catering App",
desc:"Mobile application for catering services",
tech:["Flutter","Firebase","REST API"],
color:"#00f0ff"
},
{
name:"Queue Data Structure",
desc:"Implementation of queue data structure",
tech:["C","Data Structures"],
color:"#00ff88"
},
{
name:"Interactive Portfolio",
desc:"Terminal-based portfolio website",
tech:["HTML","CSS","JavaScript"],
color:"#ff00ff"
}
];

projects.forEach(project=>{
const card=createCard(`
<h3 style="margin:0 0 10px 0;color:${project.color};font-size:1.4em;font-family:'Orbitron',sans-serif;">${project.name}</h3>
<p style="margin:0 0 15px 0;color:rgba(255,255,255,0.8);line-height:1.6;">${project.desc}</p>
<div style="display:flex;flex-wrap:wrap;gap:8px;">
${project.tech.map(t=>`<span style="background:rgba(255,255,255,0.1);padding:5px 12px;border-radius:15px;font-size:0.85em;border:1px solid ${project.color}44;color:${project.color};">${t}</span>`).join("")}
</div>
`);
display.appendChild(card);
});
animateCards();
}

else if(cmd==="contact"){
const card=createCard(`
<div style="text-align:center;">
<h3 style="font-family:'Orbitron',sans-serif;font-size:1.8em;margin-bottom:20px;color:#00f0ff;">Get In Touch</h3>
<div style="font-size:1.1em;line-height:2;">
<p style="margin:15px 0;">
<span style="color:#00f0ff;">📧</span> 
<a href="mailto:your@email.com" style="color:#00ff88;text-decoration:none;transition:all 0.3s;" onmouseover="this.style.textShadow='0 0 10px #00ff88';this.style.color='#00f0ff';" onmouseout="this.style.textShadow='none';this.style.color='#00ff88';">your@email.com</a>
</p>
<p style="margin:15px 0;">
<span style="color:#00f0ff;">💼</span> 
<a href="https://linkedin.com" target="_blank" style="color:#00ff88;text-decoration:none;transition:all 0.3s;" onmouseover="this.style.textShadow='0 0 10px #00ff88';this.style.color='#00f0ff';" onmouseout="this.style.textShadow='none';this.style.color='#00ff88';">LinkedIn</a>
</p>
<p style="margin:15px 0;">
<span style="color:#00f0ff;">🐙</span> 
<a href="https://github.com" target="_blank" style="color:#00ff88;text-decoration:none;transition:all 0.3s;" onmouseover="this.style.textShadow='0 0 10px #00ff88';this.style.color='#00f0ff';" onmouseout="this.style.textShadow='none';this.style.color='#00ff88';">GitHub</a>
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
<div class="card-glow"></div>
<h2 class="typing-text">Welcome</h2>
<p>Type <b class="highlight">help</b> in terminal</p>
<div class="sparkle">✨</div>
</div>
`;
animateCards();
}

else{
const card=createCard(`
<div style="text-align:center;">
<span style="color:#ff5f56;font-size:2em;">⚠</span>
<h3 style="margin:10px 0;color:#ff5f56;">Command not found</h3>
<p style="color:rgba(255,255,255,0.7);">Type <span style="color:#00f0ff;">help</span> to see available commands</p>
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