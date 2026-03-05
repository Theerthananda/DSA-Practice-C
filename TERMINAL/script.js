const input=document.getElementById("cmd");
const display=document.getElementById("display");

input.addEventListener("keydown",function(e){

if(e.key==="Enter"){

runCommand(input.value.toLowerCase());
input.value="";

}

});

function runCommand(cmd){

if(cmd==="help"){

display.innerHTML=`

<div class="card">about</div>
<div class="card">skills</div>
<div class="card">projects</div>
<div class="card">contact</div>

`;

}

else if(cmd==="about"){

display.innerHTML=`

<div class="card big">
<h2>Your Name</h2>
<p>MSc Computer Science Student</p>
<p>Flutter Developer</p>
</div>

`;

}

else if(cmd==="skills"){

display.innerHTML=`

<div class="card">C Programming</div>
<div class="card">Flutter</div>
<div class="card">Node.js</div>
<div class="card">MySQL</div>

`;

}

else if(cmd==="projects"){

display.innerHTML=`

<div class="card">Go Catering App</div>
<div class="card">Queue Data Structure</div>

`;

}

else if(cmd==="contact"){

display.innerHTML=`

<div class="card">
Email: your@email.com
</div>

`;

}

else if(cmd==="clear"){

display.innerHTML="";

}

else{

display.innerHTML=`<div class="card">Command not found</div>`;

}

}