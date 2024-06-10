let nb = null
let taille = null
let show = false
window.addEventListener('resize',function(){
    if(document.body.offsetWidth>=974){
        nb = [{"gauche":0,"droite":1},{"gauche":0,"droite":1}]
        taille = [0,0]
    }
    else if(document.body.offsetWidth<974 && document.body.offsetWidth>625){
        nb = [{"gauche":0,"droite":3},{"gauche":0,"droite":3}]
        taille = [0,0]
    }
    else{
        nb = [{"gauche":0,"droite":4},{"gauche":0,"droite":4}]
        taille = [0,0]
    }
})
if(document.body.offsetWidth>=974){
    nb = [{"gauche":0,"droite":1},{"gauche":0,"droite":1}]
    taille = [0,0]
}
else if(document.body.offsetWidth<974 && document.body.offsetWidth>625){
    nb = [{"gauche":0,"droite":3},{"gauche":0,"droite":3}]
    taille = [0,0]
}
else{
    nb = [{"gauche":0,"droite":4},{"gauche":0,"droite":4}]
    taille = [0,0]
}
function carouselle(slide,parent,i){
    let produit = document.querySelector(parent)
    let child = produit.querySelectorAll(".items-produit")
    let tailleOrigin = 0
    if(document.body.offsetWidth>974){
        tailleOrigin = produit.offsetWidth/4
    }
    else if(document.body.offsetWidth<974 && document.body.offsetWidth>625){
        tailleOrigin = produit.offsetWidth/2+30
    }
    else{
        tailleOrigin = produit.offsetWidth+30
    }
    if(slide == 'gauche'){
        if(nb[i].gauche != 0){
        taille[i]+=tailleOrigin
        child.forEach(element => {
            element.style=`transform:translateX(${taille[i]}px)`
        });
        nb[i].gauche-=1
        nb[i].droite+=1
        console.log(nb[i].gauche)
        }
    }
    if(slide == 'droite'){
        if(nb[i].droite != 0){
        taille[i]-=tailleOrigin
        child.forEach(element => {
            element.style=`transform:translateX(${taille[i]}px)`
        });
        nb[i].gauche+=1
        nb[i].droite-=1
        }
    }
}    

function showMenu(){
    let menu = document.querySelector(".menu-slide")
    menu.style = "top:0px"
}
function hiddenMenu(){
    let menu = document.querySelector(".menu-slide")
    menu.style = "top:-500px"
}