function buttonPress() {
    var user_ucid = document.getElementById("ucid").value;
    var valid_ucids = ["cso5", "gfd23", "moe03"];
    
    var ucid_template = /^[A-Za-z]+(\d{0,3})$/;

    if(ucid_template.test(user_ucid)){
        if(valid_ucids.includes(user_ucid)){
            alert("VALID UCID FORMAT AND UCID FOUND");
        }
        else{alert("VALID UCID FORMAT BUT INVALID UCID");}
    }
    else{
        alert("UCID DOES NOT CONFORM TO VALID FORMAT");
    }

}
