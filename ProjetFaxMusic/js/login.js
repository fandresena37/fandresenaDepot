document.querySelector("#username").value = ""
let dataLogin = null
async function getLogin(){
    const data = await fetch("../json/login.json")
    const dataSplit = await data.json()
    return dataSplit
}
getLogin()
.then((data)=>{
    dataLogin = data
})
.catch(()=>{
    console.error("erreur")
})
function Connexion(){
    let userValue = document.querySelector("#username").value
    let passValue = document.querySelector("#password").value
    dataLogin.forEach(element => {
        console.log(element.username)
        console.log(element.password)
        if(userValue == element.username && passValue == element.password){
            localStorage.setItem("user",userValue)
            window.location.href="./accueil.html"
        }
    })
}
function showChargement(){

}