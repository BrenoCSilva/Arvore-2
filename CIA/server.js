require("dotenv").config({ quiet: true });
const express = require("express");
const app = express();

const mongoose = require("mongoose");

mongoose.connect(process.env.CONNECTIONSTRING)
    .then(() => {
        console.log("Carregando banco de dados");
        app.emit("Finalizado")
    })
    .catch(e => console.log(e));


const session = require("express-session");
const MongoStore = require("connect-mongo")(session);
const flash = require("connect-flash");

const rotas = require("./routes");
const path = require("path");
const { middlewareGlobal } = require("./src/middlewares/middleware");



const sessionOptions = session({
    secret: "Coisas aleatórias",
    store: new MongoStore({ mongooseConnection: mongoose.connection }),
    resave: false,
    saveUninitialized: false,
    cookie: {
        maxAge: 1000 * 60 * 60 * 24 * 7,
        httpOnly: true
    }
});

app.use(sessionOptions);
app.use(flash());

app.use(middlewareGlobal);


app.use(express.urlencoded({ extended: true }));
app.use(express.static(path.resolve(__dirname, "public"))); // conceder a permissão de acesso ao express do empacotamento(bundle em public) feito pelo webpack


app.set("views", path.resolve(__dirname, "src", "views")); // permite que o servido, express, quando abrir o navehador tenha acesso ao HTML
app.set("view engine", "ejs")

app.use(rotas);


app.on("Finalizado", () => {
    app.listen(3000, "0.0.0.0", () => {
        console.log("Acessar http://localhost:3000");
        console.log("Servidor executando");
    });
})

