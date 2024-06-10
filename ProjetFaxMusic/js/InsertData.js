let newArrivage = null
let BestPrice = null
let BestIntru = null
let Onsale = null
let view = null
let MonPanier = null
if(localStorage.getItem("panier")!=null){
    MonPanier = JSON.parse(localStorage.getItem("panier"))
    NbItteration()
}
else{
    MonPanier = []
}
/**
 * @param {string} json 
 * @returns {json}
 */
async function getData(json){
    let data = await fetch(json)
    let dataSplit = data.json()
    return dataSplit;
}

///maka ny donnee

async function DataFetch(){
    newArrivage = await getData("../json/NewArrivage.json")
    Change(newArrivage,".new-arrivage .produit")
    BestPrice = await getData("../json/BestPrice.json")
    ChangeData(0)
    BestIntru = await getData("../json/BestIntru.json")
    Change(BestIntru,".best-intru .produit")
    Onsale = await getData("../json/Onsale.json")
    Change(Onsale,".sale2 .produit")
    removeChargement()
}
DataFetch()
/**
 * 
 * @param {json} donnee 
 * @param {string} container 
 */

function Change(donnee,container){
    let Container = document.querySelector(container)
    let template = document.getElementById("template-produit")
    donnee.forEach(element => {
        let items = template.content.cloneNode(true)
        let img = items.querySelector("img")
        img.src = "../Img/"+element.src
        let desc = items.querySelector(".description")
        desc.innerText = element.desc
        let price = items.querySelector(".price")
        price.innerText = "$"+element.price.toFixed(2)
        let button = items.querySelector("button")
        button.addEventListener('click',()=>addCart(element))
        Container.appendChild(items)
    })
}


/**
 * @param {number} index 
 */

/// changer donner sur les onglets

function ChangeData (index){
    let container = document.querySelector(".best-price .produit")
    if(index !=view){
        ChangeActive(index)
    }
    switch (index){
        case 0: 
            if(view != index){
            container.innerHTML=""    
            Change(BestPrice.GuitElect,".best-price .produit")
            view = index
            break
            }
        case 1:
            if(view != index){
            container.innerHTML=""    
            Change(BestPrice.GuitAcoust,".best-price .produit")
            view = index
            }
            break
        case 2:
            if(view != index){
            container.innerHTML=""    
            Change(BestPrice.Drums,".best-price .produit")
            view = index
            break
            }
        case 3:  
            if(view != index){
            container.innerHTML=""    
            Change(BestPrice.Orchestrale,".best-price .produit")
            view = index
            }
            break    
        case 4:
            if(view != index){
            container.innerHTML=""    
            Change(BestPrice.Autre,".best-price .produit")
            view = index
            }
            break      
    }
}

/**
 * 
 * @param {number} index 
 */

/// changer l'onglet actif

function ChangeActive(index){
    let list = document.querySelectorAll(".best-price nav ul li")
    list.forEach((li)=>{
        if(li.getAttribute("id")==""+index){
            li.classList.add("list-active")
        }
        else{
        li.classList.remove("list-active")
        }
    })

}


/// ajouter au panier

function addCart(donnee){
    let exit = false
    let nb = 0
    if(MonPanier.length!=0){
        MonPanier.forEach(element=>{
            if(element.id == donnee.id){
                element.nb+=1
                exit = true
            }
        })
        if(!exit){
            donnee.nb = 1
            MonPanier.push(donnee)
        }
    }
    else{
        donnee.nb = 1
        MonPanier.push(donnee)
    }
    localStorage.setItem("panier",JSON.stringify(MonPanier))
    NbItteration()
}

/// afficher le panier

function showCart(){
    if(MonPanier.length!=0){
    let panier = document.getElementById("monpanier")
    let panierClone = panier.content.cloneNode(true)
    let items = panierClone.querySelector(".panier-produit .prod-princ .prod-items")
    let princ = panierClone.querySelector(".prod-princ")
    let labelTotal = panierClone.querySelector(".total")
    let total = 0
    princ.innerHTML=""
    MonPanier.forEach(element=>{
        let itemsClone = items.cloneNode(true)
        let img = itemsClone.querySelector("img")
        img.src = "../Img/"+element.src
        let desc = itemsClone.querySelector(".desc")
        desc.innerText = element.desc
        let nb = itemsClone.querySelector("input")
        nb.addEventListener("change",()=>ChangeNb(element.id,nb))
        nb.value = element.nb
        let price = itemsClone.querySelector(".panier-price")
        price.innerText = "$"+(element.price * element.nb).toFixed(2)
        let remove = itemsClone.querySelector(".delete")
        remove.addEventListener('click',()=>removeProduit(element.id))
        total+=(element.price * element.nb)
        princ.appendChild(itemsClone)
    })
    labelTotal.innerText = "TOTAL : $"+total.toFixed(2)
    document.body.appendChild(panierClone)
    }
    else{
        let panier = document.getElementById("panier-vide")
        let panierClone = panier.content.cloneNode(true)
        document.body.appendChild(panierClone)
    }
    document.body.style="overflow:hidden"
}


/// supprimer le panier

function hiddenCart(){
    document.body.removeChild(document.body.querySelector(".panier-float"))
    document.body.style="overflow:scroll"
}

/// change le nombre de produit dans le panier

function ChangeNb(index,element){
    MonPanier.forEach(elt=>{
        if(elt.id == index){
            elt.nb = parseInt(element.value)
        }
    })
    localStorage.setItem("panier",JSON.stringify(MonPanier))
    hiddenCart()
    showCart()
    NbItteration()
}

/// change le nombre visisble sur le panier

function NbItteration(){
    let CartNb = document.querySelector(".cart-nb")
    let nb = 0
    if(MonPanier.length!=0){
    MonPanier.forEach(elt=>{
        nb+=parseInt(elt.nb)
    })
    CartNb.style="display:flex"
    CartNb.innerHTML = nb
    }
    else{
        CartNb.style="display:none"
    }
}

/// supprime un produit dans le panier

function removeProduit(index){
    const MonPanierTmp = MonPanier.filter(element=>element.id!==index)
    MonPanier = MonPanierTmp
    localStorage.setItem("panier",JSON.stringify(MonPanier))
    hiddenCart()
    showCart()   
    NbItteration()
}

//supprime le chargement

function removeChargement(){
    const delay = setTimeout(()=>{
        let divPrinc = document.querySelector(".chargement-princ")
        document.body.removeChild(divPrinc)
        setTimeout(delay)
    },2500)
}

function deconnexion(){
    localStorage.setItem("user","")
    window.location.href="./login.html"
}