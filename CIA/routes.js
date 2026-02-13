const express = require("express");
const route = express.Router();

const homeController = require("./src/controllers/homeController");
const loginController = require("./src/controllers/loginController");
const arvoreController = require("./src/controllers/arvoreController");

const {loginRequired} = require("./src/middlewares/middleware");
// rota home
route.get('/', homeController.index);

// rotas de login

route.get("/login",loginController.index); 
route.post("/login/register",loginController.register);
route.post("/login/login",loginController.login);
route.get("/login/logout",loginController.logout);


// rotas das arvores

route.get("/arvore/index", loginRequired, arvoreController.index);
route.post("/arvore/register", loginRequired, arvoreController.register);
route.get("/arvore/index/:id", loginRequired, arvoreController.editIndex);
route.post("/arvore/edit/:id", loginRequired, arvoreController.edit);
route.get("/arvore/delete/:id", loginRequired, arvoreController.delete);

// Rota que o ESP32 vai acessar: /api/arvore/VALOR_DO_UID
route.get('/api/arvore/:uid', arvoreController.getArvoreJson);


module.exports = route;