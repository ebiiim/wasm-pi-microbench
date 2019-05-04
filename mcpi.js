
function mcpi(loop){
    let c = 0;
    for (let i=0; i<loop; i++){
        const x = Math.random();
        const y = Math.random();
        if (x*x + y*y <= 1) c++;
    }
    return c/loop*4.0
}

function calcMcpi() {
    const iter = 100000000;
    const start = new Date();
    const pi = mcpi(iter);
    const end = new Date();
    const elapsed = end.getTime() - start.getTime();
    const log1 = 'elapsed time: '+elapsed+' ms';
    const log2 = 'iterations: '+iter+', estimated value: '+pi;
    console.log(log1+'\n'+log2);
    document.getElementById('resultJS').innerHTML = log1+'<br>'+log2;
}
