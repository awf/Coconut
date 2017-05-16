#ifndef __USECASES_BA_3_H__ 
#define __USECASES_BA_3_H__ 
#include "../../Runtime/C/fsharp.h"
#include <stdio.h>
#include <math.h>
#include "linalg.h"
#include "usecases_ba.h"
typedef struct env_t_1301 {
	array_array_number_t x;
	array_number_t w;
	array_array_number_t obs;
	array_array_number_t feat;
	array_array_number_t cams;
} env_t_1301;
env_t_1301 make_env_t_1301(array_array_number_t x,array_number_t w,array_array_number_t obs,array_array_number_t feat,array_array_number_t cams) {
	env_t_1301 env;
	env.x = x;
	env.w = w;
	env.obs = obs;
	env.feat = feat;
	env.cams = cams;
	return env;
}
typedef empty_env_t env_t_1302;


value_t lambda1302(env_t_1302* env576, number_t x1, number_t y0) {
	
	value_t res;
	res.number_t_value = (x1) - (y0);
	return res;
}
typedef struct env_t_1303 {
	array_number_t cam;
} env_t_1303;
env_t_1303 make_env_t_1303(array_number_t cam) {
	env_t_1303 env;
	env.cam = cam;
	return env;
}

value_t lambda1303(env_t_1303* env580, index_t i2) {
	array_number_t cam579 = env580->cam;
	value_t res;
	res.number_t_value = cam579->arr[(i2) + (3)];
	return res;
}
typedef empty_env_t env_t_1304;


value_t lambda1304(env_t_1304* env584, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_1305 {
	array_number_t cam;
} env_t_1305;
env_t_1305 make_env_t_1305(array_number_t cam) {
	env_t_1305 env;
	env.cam = cam;
	return env;
}

value_t lambda1305(env_t_1305* env588, index_t i2) {
	array_number_t cam587 = env588->cam;
	value_t res;
	res.number_t_value = cam587->arr[(i2) + (0)];
	return res;
}
typedef struct env_t_1306 {
	number_t theta_inv;
} env_t_1306;
env_t_1306 make_env_t_1306(number_t theta_inv) {
	env_t_1306 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1306(env_t_1306* env594, number_t a) {
	number_t theta_inv593 = env594->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv593);
	return res;
}
typedef struct env_t_1307 {
	array_number_t cam;
} env_t_1307;
env_t_1307 make_env_t_1307(array_number_t cam) {
	env_t_1307 env;
	env.cam = cam;
	return env;
}

value_t lambda1307(env_t_1307* env598, index_t i2) {
	array_number_t cam597 = env598->cam;
	value_t res;
	res.number_t_value = cam597->arr[(i2) + (0)];
	return res;
}
typedef struct env_t_1308 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1308;
env_t_1308 make_env_t_1308(number_t theta_inv,array_number_t cam) {
	env_t_1308 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1309 {
	number_t theta_inv;
} env_t_1309;
env_t_1309 make_env_t_1309(number_t theta_inv) {
	env_t_1309 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1309(env_t_1309* env603, number_t a) {
	number_t theta_inv602 = env603->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv602);
	return res;
}
typedef struct env_t_1310 {
	array_number_t cam;
} env_t_1310;
env_t_1310 make_env_t_1310(array_number_t cam) {
	env_t_1310 env;
	env.cam = cam;
	return env;
}

value_t lambda1310(env_t_1310* env607, index_t i2) {
	array_number_t cam606 = env607->cam;
	value_t res;
	res.number_t_value = cam606->arr[(i2) + (0)];
	return res;
}
value_t lambda1308(env_t_1308* env612, index_t i1) {
	number_t theta_inv611 = env612->theta_inv;
	array_number_t cam610 = env612->cam;
	env_t_1309 env_t_1309_value = make_env_t_1309(theta_inv611); closure_t closure605 = make_closure(lambda1309, &env_t_1309_value);
	env_t_1310 env_t_1310_value = make_env_t_1310(cam610); closure_t closure609 = make_closure(lambda1310, &env_t_1310_value);
	value_t res;
	res.number_t_value = closure605.lam(closure605.env, closure609.lam(closure609.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1311 {
	array_number_t x0;
	array_number_t cam;
} env_t_1311;
env_t_1311 make_env_t_1311(array_number_t x0,array_number_t cam) {
	env_t_1311 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1312;


value_t lambda1312(env_t_1312* env615, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1313 {
	array_number_t cam;
} env_t_1313;
env_t_1313 make_env_t_1313(array_number_t cam) {
	env_t_1313 env;
	env.cam = cam;
	return env;
}

value_t lambda1313(env_t_1313* env619, index_t i2) {
	array_number_t cam618 = env619->cam;
	value_t res;
	res.number_t_value = cam618->arr[(i2) + (3)];
	return res;
}
value_t lambda1311(env_t_1311* env624, index_t i1) {
	array_number_t x0623 = env624->x0;
	array_number_t cam622 = env624->cam;
	env_t_1312 env_t_1312_value = make_empty_env(); closure_t closure617 = make_closure(lambda1312, &env_t_1312_value);
	env_t_1313 env_t_1313_value = make_env_t_1313(cam622); closure_t closure621 = make_closure(lambda1313, &env_t_1313_value);
	value_t res;
	res.number_t_value = closure617.lam(closure617.env, x0623->arr[i1], closure621.lam(closure621.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1314 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1314;
env_t_1314 make_env_t_1314(number_t theta_inv,array_number_t cam) {
	env_t_1314 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1315 {
	number_t theta_inv;
} env_t_1315;
env_t_1315 make_env_t_1315(number_t theta_inv) {
	env_t_1315 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1315(env_t_1315* env628, number_t a) {
	number_t theta_inv627 = env628->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv627);
	return res;
}
typedef struct env_t_1316 {
	array_number_t cam;
} env_t_1316;
env_t_1316 make_env_t_1316(array_number_t cam) {
	env_t_1316 env;
	env.cam = cam;
	return env;
}

value_t lambda1316(env_t_1316* env632, index_t i2) {
	array_number_t cam631 = env632->cam;
	value_t res;
	res.number_t_value = cam631->arr[(i2) + (0)];
	return res;
}
value_t lambda1314(env_t_1314* env637, index_t i1) {
	number_t theta_inv636 = env637->theta_inv;
	array_number_t cam635 = env637->cam;
	env_t_1315 env_t_1315_value = make_env_t_1315(theta_inv636); closure_t closure630 = make_closure(lambda1315, &env_t_1315_value);
	env_t_1316 env_t_1316_value = make_env_t_1316(cam635); closure_t closure634 = make_closure(lambda1316, &env_t_1316_value);
	value_t res;
	res.number_t_value = closure630.lam(closure630.env, closure634.lam(closure634.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1317 {
	array_number_t x0;
	array_number_t cam;
} env_t_1317;
env_t_1317 make_env_t_1317(array_number_t x0,array_number_t cam) {
	env_t_1317 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1318;


value_t lambda1318(env_t_1318* env640, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1319 {
	array_number_t cam;
} env_t_1319;
env_t_1319 make_env_t_1319(array_number_t cam) {
	env_t_1319 env;
	env.cam = cam;
	return env;
}

value_t lambda1319(env_t_1319* env644, index_t i2) {
	array_number_t cam643 = env644->cam;
	value_t res;
	res.number_t_value = cam643->arr[(i2) + (3)];
	return res;
}
value_t lambda1317(env_t_1317* env649, index_t i1) {
	array_number_t x0648 = env649->x0;
	array_number_t cam647 = env649->cam;
	env_t_1318 env_t_1318_value = make_empty_env(); closure_t closure642 = make_closure(lambda1318, &env_t_1318_value);
	env_t_1319 env_t_1319_value = make_env_t_1319(cam647); closure_t closure646 = make_closure(lambda1319, &env_t_1319_value);
	value_t res;
	res.number_t_value = closure642.lam(closure642.env, x0648->arr[i1], closure646.lam(closure646.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1320 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1320;
env_t_1320 make_env_t_1320(number_t theta_inv,array_number_t cam) {
	env_t_1320 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1321 {
	number_t theta_inv;
} env_t_1321;
env_t_1321 make_env_t_1321(number_t theta_inv) {
	env_t_1321 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1321(env_t_1321* env653, number_t a) {
	number_t theta_inv652 = env653->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv652);
	return res;
}
typedef struct env_t_1322 {
	array_number_t cam;
} env_t_1322;
env_t_1322 make_env_t_1322(array_number_t cam) {
	env_t_1322 env;
	env.cam = cam;
	return env;
}

value_t lambda1322(env_t_1322* env657, index_t i2) {
	array_number_t cam656 = env657->cam;
	value_t res;
	res.number_t_value = cam656->arr[(i2) + (0)];
	return res;
}
value_t lambda1320(env_t_1320* env662, index_t i1) {
	number_t theta_inv661 = env662->theta_inv;
	array_number_t cam660 = env662->cam;
	env_t_1321 env_t_1321_value = make_env_t_1321(theta_inv661); closure_t closure655 = make_closure(lambda1321, &env_t_1321_value);
	env_t_1322 env_t_1322_value = make_env_t_1322(cam660); closure_t closure659 = make_closure(lambda1322, &env_t_1322_value);
	value_t res;
	res.number_t_value = closure655.lam(closure655.env, closure659.lam(closure659.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1323 {
	array_number_t x0;
	array_number_t cam;
} env_t_1323;
env_t_1323 make_env_t_1323(array_number_t x0,array_number_t cam) {
	env_t_1323 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1324;


value_t lambda1324(env_t_1324* env665, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1325 {
	array_number_t cam;
} env_t_1325;
env_t_1325 make_env_t_1325(array_number_t cam) {
	env_t_1325 env;
	env.cam = cam;
	return env;
}

value_t lambda1325(env_t_1325* env669, index_t i2) {
	array_number_t cam668 = env669->cam;
	value_t res;
	res.number_t_value = cam668->arr[(i2) + (3)];
	return res;
}
value_t lambda1323(env_t_1323* env674, index_t i1) {
	array_number_t x0673 = env674->x0;
	array_number_t cam672 = env674->cam;
	env_t_1324 env_t_1324_value = make_empty_env(); closure_t closure667 = make_closure(lambda1324, &env_t_1324_value);
	env_t_1325 env_t_1325_value = make_env_t_1325(cam672); closure_t closure671 = make_closure(lambda1325, &env_t_1325_value);
	value_t res;
	res.number_t_value = closure667.lam(closure667.env, x0673->arr[i1], closure671.lam(closure671.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1326 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1326;
env_t_1326 make_env_t_1326(number_t theta_inv,array_number_t cam) {
	env_t_1326 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1327 {
	number_t theta_inv;
} env_t_1327;
env_t_1327 make_env_t_1327(number_t theta_inv) {
	env_t_1327 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1327(env_t_1327* env678, number_t a) {
	number_t theta_inv677 = env678->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv677);
	return res;
}
typedef struct env_t_1328 {
	array_number_t cam;
} env_t_1328;
env_t_1328 make_env_t_1328(array_number_t cam) {
	env_t_1328 env;
	env.cam = cam;
	return env;
}

value_t lambda1328(env_t_1328* env682, index_t i2) {
	array_number_t cam681 = env682->cam;
	value_t res;
	res.number_t_value = cam681->arr[(i2) + (0)];
	return res;
}
value_t lambda1326(env_t_1326* env687, index_t i1) {
	number_t theta_inv686 = env687->theta_inv;
	array_number_t cam685 = env687->cam;
	env_t_1327 env_t_1327_value = make_env_t_1327(theta_inv686); closure_t closure680 = make_closure(lambda1327, &env_t_1327_value);
	env_t_1328 env_t_1328_value = make_env_t_1328(cam685); closure_t closure684 = make_closure(lambda1328, &env_t_1328_value);
	value_t res;
	res.number_t_value = closure680.lam(closure680.env, closure684.lam(closure684.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1329 {
	array_number_t x0;
	array_number_t cam;
} env_t_1329;
env_t_1329 make_env_t_1329(array_number_t x0,array_number_t cam) {
	env_t_1329 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1330;


value_t lambda1330(env_t_1330* env690, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1331 {
	array_number_t cam;
} env_t_1331;
env_t_1331 make_env_t_1331(array_number_t cam) {
	env_t_1331 env;
	env.cam = cam;
	return env;
}

value_t lambda1331(env_t_1331* env694, index_t i2) {
	array_number_t cam693 = env694->cam;
	value_t res;
	res.number_t_value = cam693->arr[(i2) + (3)];
	return res;
}
value_t lambda1329(env_t_1329* env699, index_t i1) {
	array_number_t x0698 = env699->x0;
	array_number_t cam697 = env699->cam;
	env_t_1330 env_t_1330_value = make_empty_env(); closure_t closure692 = make_closure(lambda1330, &env_t_1330_value);
	env_t_1331 env_t_1331_value = make_env_t_1331(cam697); closure_t closure696 = make_closure(lambda1331, &env_t_1331_value);
	value_t res;
	res.number_t_value = closure692.lam(closure692.env, x0698->arr[i1], closure696.lam(closure696.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1332 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1332;
env_t_1332 make_env_t_1332(number_t theta_inv,array_number_t cam) {
	env_t_1332 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1333 {
	number_t theta_inv;
} env_t_1333;
env_t_1333 make_env_t_1333(number_t theta_inv) {
	env_t_1333 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1333(env_t_1333* env703, number_t a) {
	number_t theta_inv702 = env703->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv702);
	return res;
}
typedef struct env_t_1334 {
	array_number_t cam;
} env_t_1334;
env_t_1334 make_env_t_1334(array_number_t cam) {
	env_t_1334 env;
	env.cam = cam;
	return env;
}

value_t lambda1334(env_t_1334* env707, index_t i2) {
	array_number_t cam706 = env707->cam;
	value_t res;
	res.number_t_value = cam706->arr[(i2) + (0)];
	return res;
}
value_t lambda1332(env_t_1332* env712, index_t i1) {
	number_t theta_inv711 = env712->theta_inv;
	array_number_t cam710 = env712->cam;
	env_t_1333 env_t_1333_value = make_env_t_1333(theta_inv711); closure_t closure705 = make_closure(lambda1333, &env_t_1333_value);
	env_t_1334 env_t_1334_value = make_env_t_1334(cam710); closure_t closure709 = make_closure(lambda1334, &env_t_1334_value);
	value_t res;
	res.number_t_value = closure705.lam(closure705.env, closure709.lam(closure709.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1335 {
	array_number_t x0;
	array_number_t cam;
} env_t_1335;
env_t_1335 make_env_t_1335(array_number_t x0,array_number_t cam) {
	env_t_1335 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1336;


value_t lambda1336(env_t_1336* env715, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1337 {
	array_number_t cam;
} env_t_1337;
env_t_1337 make_env_t_1337(array_number_t cam) {
	env_t_1337 env;
	env.cam = cam;
	return env;
}

value_t lambda1337(env_t_1337* env719, index_t i2) {
	array_number_t cam718 = env719->cam;
	value_t res;
	res.number_t_value = cam718->arr[(i2) + (3)];
	return res;
}
value_t lambda1335(env_t_1335* env724, index_t i1) {
	array_number_t x0723 = env724->x0;
	array_number_t cam722 = env724->cam;
	env_t_1336 env_t_1336_value = make_empty_env(); closure_t closure717 = make_closure(lambda1336, &env_t_1336_value);
	env_t_1337 env_t_1337_value = make_env_t_1337(cam722); closure_t closure721 = make_closure(lambda1337, &env_t_1337_value);
	value_t res;
	res.number_t_value = closure717.lam(closure717.env, x0723->arr[i1], closure721.lam(closure721.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1338 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1338;
env_t_1338 make_env_t_1338(number_t theta_inv,array_number_t cam) {
	env_t_1338 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1339 {
	number_t theta_inv;
} env_t_1339;
env_t_1339 make_env_t_1339(number_t theta_inv) {
	env_t_1339 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1339(env_t_1339* env728, number_t a) {
	number_t theta_inv727 = env728->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv727);
	return res;
}
typedef struct env_t_1340 {
	array_number_t cam;
} env_t_1340;
env_t_1340 make_env_t_1340(array_number_t cam) {
	env_t_1340 env;
	env.cam = cam;
	return env;
}

value_t lambda1340(env_t_1340* env732, index_t i2) {
	array_number_t cam731 = env732->cam;
	value_t res;
	res.number_t_value = cam731->arr[(i2) + (0)];
	return res;
}
value_t lambda1338(env_t_1338* env737, index_t i1) {
	number_t theta_inv736 = env737->theta_inv;
	array_number_t cam735 = env737->cam;
	env_t_1339 env_t_1339_value = make_env_t_1339(theta_inv736); closure_t closure730 = make_closure(lambda1339, &env_t_1339_value);
	env_t_1340 env_t_1340_value = make_env_t_1340(cam735); closure_t closure734 = make_closure(lambda1340, &env_t_1340_value);
	value_t res;
	res.number_t_value = closure730.lam(closure730.env, closure734.lam(closure734.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1341 {
	array_number_t x0;
	array_number_t cam;
} env_t_1341;
env_t_1341 make_env_t_1341(array_number_t x0,array_number_t cam) {
	env_t_1341 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1342;


value_t lambda1342(env_t_1342* env740, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1343 {
	array_number_t cam;
} env_t_1343;
env_t_1343 make_env_t_1343(array_number_t cam) {
	env_t_1343 env;
	env.cam = cam;
	return env;
}

value_t lambda1343(env_t_1343* env744, index_t i2) {
	array_number_t cam743 = env744->cam;
	value_t res;
	res.number_t_value = cam743->arr[(i2) + (3)];
	return res;
}
value_t lambda1341(env_t_1341* env749, index_t i1) {
	array_number_t x0748 = env749->x0;
	array_number_t cam747 = env749->cam;
	env_t_1342 env_t_1342_value = make_empty_env(); closure_t closure742 = make_closure(lambda1342, &env_t_1342_value);
	env_t_1343 env_t_1343_value = make_env_t_1343(cam747); closure_t closure746 = make_closure(lambda1343, &env_t_1343_value);
	value_t res;
	res.number_t_value = closure742.lam(closure742.env, x0748->arr[i1], closure746.lam(closure746.env, i1).number_t_value).number_t_value;
	return res;
}
typedef empty_env_t env_t_1344;


value_t lambda1344(env_t_1344* env752, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) * (y0);
	return res;
}
typedef struct env_t_1345 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1345;
env_t_1345 make_env_t_1345(number_t theta_inv,array_number_t cam) {
	env_t_1345 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1346 {
	number_t theta_inv;
} env_t_1346;
env_t_1346 make_env_t_1346(number_t theta_inv) {
	env_t_1346 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1346(env_t_1346* env756, number_t a) {
	number_t theta_inv755 = env756->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv755);
	return res;
}
typedef struct env_t_1347 {
	array_number_t cam;
} env_t_1347;
env_t_1347 make_env_t_1347(array_number_t cam) {
	env_t_1347 env;
	env.cam = cam;
	return env;
}

value_t lambda1347(env_t_1347* env760, index_t i3) {
	array_number_t cam759 = env760->cam;
	value_t res;
	res.number_t_value = cam759->arr[(i3) + (0)];
	return res;
}
value_t lambda1345(env_t_1345* env765, index_t i2) {
	number_t theta_inv764 = env765->theta_inv;
	array_number_t cam763 = env765->cam;
	env_t_1346 env_t_1346_value = make_env_t_1346(theta_inv764); closure_t closure758 = make_closure(lambda1346, &env_t_1346_value);
	env_t_1347 env_t_1347_value = make_env_t_1347(cam763); closure_t closure762 = make_closure(lambda1347, &env_t_1347_value);
	value_t res;
	res.number_t_value = closure758.lam(closure758.env, closure762.lam(closure762.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1348 {
	array_number_t x0;
	array_number_t cam;
} env_t_1348;
env_t_1348 make_env_t_1348(array_number_t x0,array_number_t cam) {
	env_t_1348 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1349;


value_t lambda1349(env_t_1349* env768, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1350 {
	array_number_t cam;
} env_t_1350;
env_t_1350 make_env_t_1350(array_number_t cam) {
	env_t_1350 env;
	env.cam = cam;
	return env;
}

value_t lambda1350(env_t_1350* env772, index_t i3) {
	array_number_t cam771 = env772->cam;
	value_t res;
	res.number_t_value = cam771->arr[(i3) + (3)];
	return res;
}
value_t lambda1348(env_t_1348* env777, index_t i2) {
	array_number_t x0776 = env777->x0;
	array_number_t cam775 = env777->cam;
	env_t_1349 env_t_1349_value = make_empty_env(); closure_t closure770 = make_closure(lambda1349, &env_t_1349_value);
	env_t_1350 env_t_1350_value = make_env_t_1350(cam775); closure_t closure774 = make_closure(lambda1350, &env_t_1350_value);
	value_t res;
	res.number_t_value = closure770.lam(closure770.env, x0776->arr[i2], closure774.lam(closure774.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1351 {
	number_t costheta;
} env_t_1351;
env_t_1351 make_env_t_1351(number_t costheta) {
	env_t_1351 env;
	env.costheta = costheta;
	return env;
}

value_t lambda1351(env_t_1351* env784, number_t a) {
	number_t costheta783 = env784->costheta;
	value_t res;
	res.number_t_value = (a) * (costheta783);
	return res;
}
typedef struct env_t_1352 {
	array_number_t x0;
	array_number_t cam;
} env_t_1352;
env_t_1352 make_env_t_1352(array_number_t x0,array_number_t cam) {
	env_t_1352 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1353;


value_t lambda1353(env_t_1353* env787, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1354 {
	array_number_t cam;
} env_t_1354;
env_t_1354 make_env_t_1354(array_number_t cam) {
	env_t_1354 env;
	env.cam = cam;
	return env;
}

value_t lambda1354(env_t_1354* env791, index_t i3) {
	array_number_t cam790 = env791->cam;
	value_t res;
	res.number_t_value = cam790->arr[(i3) + (3)];
	return res;
}
value_t lambda1352(env_t_1352* env796, index_t i2) {
	array_number_t x0795 = env796->x0;
	array_number_t cam794 = env796->cam;
	env_t_1353 env_t_1353_value = make_empty_env(); closure_t closure789 = make_closure(lambda1353, &env_t_1353_value);
	env_t_1354 env_t_1354_value = make_env_t_1354(cam794); closure_t closure793 = make_closure(lambda1354, &env_t_1354_value);
	value_t res;
	res.number_t_value = closure789.lam(closure789.env, x0795->arr[i2], closure793.lam(closure793.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1355 {
	number_t sintheta;
} env_t_1355;
env_t_1355 make_env_t_1355(number_t sintheta) {
	env_t_1355 env;
	env.sintheta = sintheta;
	return env;
}

value_t lambda1355(env_t_1355* env802, number_t a) {
	number_t sintheta801 = env802->sintheta;
	value_t res;
	res.number_t_value = (a) * (sintheta801);
	return res;
}
typedef empty_env_t env_t_1356;


value_t lambda1356(env_t_1356* env807, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) + (y0);
	return res;
}
typedef struct env_t_1357 {
	array_number_t x0;
	number_t costheta;
	array_number_t cam;
} env_t_1357;
env_t_1357 make_env_t_1357(array_number_t x0,number_t costheta,array_number_t cam) {
	env_t_1357 env;
	env.x0 = x0;
	env.costheta = costheta;
	env.cam = cam;
	return env;
}
typedef struct env_t_1358 {
	number_t costheta;
} env_t_1358;
env_t_1358 make_env_t_1358(number_t costheta) {
	env_t_1358 env;
	env.costheta = costheta;
	return env;
}

value_t lambda1358(env_t_1358* env811, number_t a) {
	number_t costheta810 = env811->costheta;
	value_t res;
	res.number_t_value = (a) * (costheta810);
	return res;
}
typedef struct env_t_1359 {
	array_number_t x0;
	array_number_t cam;
} env_t_1359;
env_t_1359 make_env_t_1359(array_number_t x0,array_number_t cam) {
	env_t_1359 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1360;


value_t lambda1360(env_t_1360* env814, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1361 {
	array_number_t cam;
} env_t_1361;
env_t_1361 make_env_t_1361(array_number_t cam) {
	env_t_1361 env;
	env.cam = cam;
	return env;
}

value_t lambda1361(env_t_1361* env818, index_t i4) {
	array_number_t cam817 = env818->cam;
	value_t res;
	res.number_t_value = cam817->arr[(i4) + (3)];
	return res;
}
value_t lambda1359(env_t_1359* env823, index_t i3) {
	array_number_t x0822 = env823->x0;
	array_number_t cam821 = env823->cam;
	env_t_1360 env_t_1360_value = make_empty_env(); closure_t closure816 = make_closure(lambda1360, &env_t_1360_value);
	env_t_1361 env_t_1361_value = make_env_t_1361(cam821); closure_t closure820 = make_closure(lambda1361, &env_t_1361_value);
	value_t res;
	res.number_t_value = closure816.lam(closure816.env, x0822->arr[i3], closure820.lam(closure820.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1357(env_t_1357* env829, index_t i2) {
	array_number_t x0828 = env829->x0;
	number_t costheta827 = env829->costheta;
	array_number_t cam826 = env829->cam;
	env_t_1358 env_t_1358_value = make_env_t_1358(costheta827); closure_t closure813 = make_closure(lambda1358, &env_t_1358_value);
	env_t_1359 env_t_1359_value = make_env_t_1359(x0828,cam826); closure_t closure825 = make_closure(lambda1359, &env_t_1359_value);
	value_t res;
	res.number_t_value = closure813.lam(closure813.env, closure825.lam(closure825.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1362 {
	array_number_t w_cross_X;
	number_t sintheta;
} env_t_1362;
env_t_1362 make_env_t_1362(array_number_t w_cross_X,number_t sintheta) {
	env_t_1362 env;
	env.w_cross_X = w_cross_X;
	env.sintheta = sintheta;
	return env;
}
typedef struct env_t_1363 {
	number_t sintheta;
} env_t_1363;
env_t_1363 make_env_t_1363(number_t sintheta) {
	env_t_1363 env;
	env.sintheta = sintheta;
	return env;
}

value_t lambda1363(env_t_1363* env833, number_t a) {
	number_t sintheta832 = env833->sintheta;
	value_t res;
	res.number_t_value = (a) * (sintheta832);
	return res;
}
value_t lambda1362(env_t_1362* env838, index_t i2) {
	array_number_t w_cross_X837 = env838->w_cross_X;
	number_t sintheta836 = env838->sintheta;
	env_t_1363 env_t_1363_value = make_env_t_1363(sintheta836); closure_t closure835 = make_closure(lambda1363, &env_t_1363_value);
	value_t res;
	res.number_t_value = closure835.lam(closure835.env, w_cross_X837->arr[i2]).number_t_value;
	return res;
}
typedef struct env_t_1364 {
	number_t tmp;
} env_t_1364;
env_t_1364 make_env_t_1364(number_t tmp) {
	env_t_1364 env;
	env.tmp = tmp;
	return env;
}

value_t lambda1364(env_t_1364* env843, number_t a) {
	number_t tmp842 = env843->tmp;
	value_t res;
	res.number_t_value = (a) * (tmp842);
	return res;
}
typedef struct env_t_1365 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1365;
env_t_1365 make_env_t_1365(number_t theta_inv,array_number_t cam) {
	env_t_1365 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1366 {
	number_t theta_inv;
} env_t_1366;
env_t_1366 make_env_t_1366(number_t theta_inv) {
	env_t_1366 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1366(env_t_1366* env847, number_t a) {
	number_t theta_inv846 = env847->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv846);
	return res;
}
typedef struct env_t_1367 {
	array_number_t cam;
} env_t_1367;
env_t_1367 make_env_t_1367(array_number_t cam) {
	env_t_1367 env;
	env.cam = cam;
	return env;
}

value_t lambda1367(env_t_1367* env851, index_t i3) {
	array_number_t cam850 = env851->cam;
	value_t res;
	res.number_t_value = cam850->arr[(i3) + (0)];
	return res;
}
value_t lambda1365(env_t_1365* env856, index_t i2) {
	number_t theta_inv855 = env856->theta_inv;
	array_number_t cam854 = env856->cam;
	env_t_1366 env_t_1366_value = make_env_t_1366(theta_inv855); closure_t closure849 = make_closure(lambda1366, &env_t_1366_value);
	env_t_1367 env_t_1367_value = make_env_t_1367(cam854); closure_t closure853 = make_closure(lambda1367, &env_t_1367_value);
	value_t res;
	res.number_t_value = closure849.lam(closure849.env, closure853.lam(closure853.env, i2).number_t_value).number_t_value;
	return res;
}
typedef empty_env_t env_t_1368;


value_t lambda1368(env_t_1368* env861, number_t x3, number_t y1) {
	
	value_t res;
	res.number_t_value = (x3) + (y1);
	return res;
}
typedef struct env_t_1369 {
	array_number_t x0;
	array_number_t w_cross_X;
	number_t sintheta;
	number_t costheta;
	array_number_t cam;
} env_t_1369;
env_t_1369 make_env_t_1369(array_number_t x0,array_number_t w_cross_X,number_t sintheta,number_t costheta,array_number_t cam) {
	env_t_1369 env;
	env.x0 = x0;
	env.w_cross_X = w_cross_X;
	env.sintheta = sintheta;
	env.costheta = costheta;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1370;


value_t lambda1370(env_t_1370* env864, number_t x3, number_t y1) {
	
	value_t res;
	res.number_t_value = (x3) + (y1);
	return res;
}
typedef struct env_t_1371 {
	array_number_t x0;
	number_t costheta;
	array_number_t cam;
} env_t_1371;
env_t_1371 make_env_t_1371(array_number_t x0,number_t costheta,array_number_t cam) {
	env_t_1371 env;
	env.x0 = x0;
	env.costheta = costheta;
	env.cam = cam;
	return env;
}
typedef struct env_t_1372 {
	number_t costheta;
} env_t_1372;
env_t_1372 make_env_t_1372(number_t costheta) {
	env_t_1372 env;
	env.costheta = costheta;
	return env;
}

value_t lambda1372(env_t_1372* env868, number_t a) {
	number_t costheta867 = env868->costheta;
	value_t res;
	res.number_t_value = (a) * (costheta867);
	return res;
}
typedef struct env_t_1373 {
	array_number_t x0;
	array_number_t cam;
} env_t_1373;
env_t_1373 make_env_t_1373(array_number_t x0,array_number_t cam) {
	env_t_1373 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1374;


value_t lambda1374(env_t_1374* env871, number_t x3, number_t y1) {
	
	value_t res;
	res.number_t_value = (x3) - (y1);
	return res;
}
typedef struct env_t_1375 {
	array_number_t cam;
} env_t_1375;
env_t_1375 make_env_t_1375(array_number_t cam) {
	env_t_1375 env;
	env.cam = cam;
	return env;
}

value_t lambda1375(env_t_1375* env875, index_t i5) {
	array_number_t cam874 = env875->cam;
	value_t res;
	res.number_t_value = cam874->arr[(i5) + (3)];
	return res;
}
value_t lambda1373(env_t_1373* env880, index_t i4) {
	array_number_t x0879 = env880->x0;
	array_number_t cam878 = env880->cam;
	env_t_1374 env_t_1374_value = make_empty_env(); closure_t closure873 = make_closure(lambda1374, &env_t_1374_value);
	env_t_1375 env_t_1375_value = make_env_t_1375(cam878); closure_t closure877 = make_closure(lambda1375, &env_t_1375_value);
	value_t res;
	res.number_t_value = closure873.lam(closure873.env, x0879->arr[i4], closure877.lam(closure877.env, i4).number_t_value).number_t_value;
	return res;
}
value_t lambda1371(env_t_1371* env886, index_t i3) {
	array_number_t x0885 = env886->x0;
	number_t costheta884 = env886->costheta;
	array_number_t cam883 = env886->cam;
	env_t_1372 env_t_1372_value = make_env_t_1372(costheta884); closure_t closure870 = make_closure(lambda1372, &env_t_1372_value);
	env_t_1373 env_t_1373_value = make_env_t_1373(x0885,cam883); closure_t closure882 = make_closure(lambda1373, &env_t_1373_value);
	value_t res;
	res.number_t_value = closure870.lam(closure870.env, closure882.lam(closure882.env, i3).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1376 {
	array_number_t w_cross_X;
	number_t sintheta;
} env_t_1376;
env_t_1376 make_env_t_1376(array_number_t w_cross_X,number_t sintheta) {
	env_t_1376 env;
	env.w_cross_X = w_cross_X;
	env.sintheta = sintheta;
	return env;
}
typedef struct env_t_1377 {
	number_t sintheta;
} env_t_1377;
env_t_1377 make_env_t_1377(number_t sintheta) {
	env_t_1377 env;
	env.sintheta = sintheta;
	return env;
}

value_t lambda1377(env_t_1377* env890, number_t a) {
	number_t sintheta889 = env890->sintheta;
	value_t res;
	res.number_t_value = (a) * (sintheta889);
	return res;
}
value_t lambda1376(env_t_1376* env895, index_t i3) {
	array_number_t w_cross_X894 = env895->w_cross_X;
	number_t sintheta893 = env895->sintheta;
	env_t_1377 env_t_1377_value = make_env_t_1377(sintheta893); closure_t closure892 = make_closure(lambda1377, &env_t_1377_value);
	value_t res;
	res.number_t_value = closure892.lam(closure892.env, w_cross_X894->arr[i3]).number_t_value;
	return res;
}
value_t lambda1369(env_t_1369* env903, index_t i2) {
	array_number_t x0902 = env903->x0;
	array_number_t w_cross_X901 = env903->w_cross_X;
	number_t sintheta900 = env903->sintheta;
	number_t costheta899 = env903->costheta;
	array_number_t cam898 = env903->cam;
	env_t_1370 env_t_1370_value = make_empty_env(); closure_t closure866 = make_closure(lambda1370, &env_t_1370_value);
	env_t_1371 env_t_1371_value = make_env_t_1371(x0902,costheta899,cam898); closure_t closure888 = make_closure(lambda1371, &env_t_1371_value);
	env_t_1376 env_t_1376_value = make_env_t_1376(w_cross_X901,sintheta900); closure_t closure897 = make_closure(lambda1376, &env_t_1376_value);
	value_t res;
	res.number_t_value = closure866.lam(closure866.env, closure888.lam(closure888.env, i2).number_t_value, closure897.lam(closure897.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1378 {
	number_t tmp;
	number_t theta_inv;
	array_number_t cam;
} env_t_1378;
env_t_1378 make_env_t_1378(number_t tmp,number_t theta_inv,array_number_t cam) {
	env_t_1378 env;
	env.tmp = tmp;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1379 {
	number_t tmp;
} env_t_1379;
env_t_1379 make_env_t_1379(number_t tmp) {
	env_t_1379 env;
	env.tmp = tmp;
	return env;
}

value_t lambda1379(env_t_1379* env907, number_t a) {
	number_t tmp906 = env907->tmp;
	value_t res;
	res.number_t_value = (a) * (tmp906);
	return res;
}
typedef struct env_t_1380 {
	number_t theta_inv;
	array_number_t cam;
} env_t_1380;
env_t_1380 make_env_t_1380(number_t theta_inv,array_number_t cam) {
	env_t_1380 env;
	env.theta_inv = theta_inv;
	env.cam = cam;
	return env;
}
typedef struct env_t_1381 {
	number_t theta_inv;
} env_t_1381;
env_t_1381 make_env_t_1381(number_t theta_inv) {
	env_t_1381 env;
	env.theta_inv = theta_inv;
	return env;
}

value_t lambda1381(env_t_1381* env911, number_t a) {
	number_t theta_inv910 = env911->theta_inv;
	value_t res;
	res.number_t_value = (a) * (theta_inv910);
	return res;
}
typedef struct env_t_1382 {
	array_number_t cam;
} env_t_1382;
env_t_1382 make_env_t_1382(array_number_t cam) {
	env_t_1382 env;
	env.cam = cam;
	return env;
}

value_t lambda1382(env_t_1382* env915, index_t i4) {
	array_number_t cam914 = env915->cam;
	value_t res;
	res.number_t_value = cam914->arr[(i4) + (0)];
	return res;
}
value_t lambda1380(env_t_1380* env920, index_t i3) {
	number_t theta_inv919 = env920->theta_inv;
	array_number_t cam918 = env920->cam;
	env_t_1381 env_t_1381_value = make_env_t_1381(theta_inv919); closure_t closure913 = make_closure(lambda1381, &env_t_1381_value);
	env_t_1382 env_t_1382_value = make_env_t_1382(cam918); closure_t closure917 = make_closure(lambda1382, &env_t_1382_value);
	value_t res;
	res.number_t_value = closure913.lam(closure913.env, closure917.lam(closure917.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1378(env_t_1378* env926, index_t i2) {
	number_t tmp925 = env926->tmp;
	number_t theta_inv924 = env926->theta_inv;
	array_number_t cam923 = env926->cam;
	env_t_1379 env_t_1379_value = make_env_t_1379(tmp925); closure_t closure909 = make_closure(lambda1379, &env_t_1379_value);
	env_t_1380 env_t_1380_value = make_env_t_1380(theta_inv924,cam923); closure_t closure922 = make_closure(lambda1380, &env_t_1380_value);
	value_t res;
	res.number_t_value = closure909.lam(closure909.env, closure922.lam(closure922.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1383 {
	array_number_t cam;
} env_t_1383;
env_t_1383 make_env_t_1383(array_number_t cam) {
	env_t_1383 env;
	env.cam = cam;
	return env;
}

value_t lambda1383(env_t_1383* env931, index_t i1) {
	array_number_t cam930 = env931->cam;
	value_t res;
	res.number_t_value = cam930->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1384 {
	array_number_t x0;
	array_number_t cam;
} env_t_1384;
env_t_1384 make_env_t_1384(array_number_t x0,array_number_t cam) {
	env_t_1384 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1385;


value_t lambda1385(env_t_1385* env934, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1386 {
	array_number_t cam;
} env_t_1386;
env_t_1386 make_env_t_1386(array_number_t cam) {
	env_t_1386 env;
	env.cam = cam;
	return env;
}

value_t lambda1386(env_t_1386* env938, index_t i2) {
	array_number_t cam937 = env938->cam;
	value_t res;
	res.number_t_value = cam937->arr[(i2) + (3)];
	return res;
}
value_t lambda1384(env_t_1384* env943, index_t i1) {
	array_number_t x0942 = env943->x0;
	array_number_t cam941 = env943->cam;
	env_t_1385 env_t_1385_value = make_empty_env(); closure_t closure936 = make_closure(lambda1385, &env_t_1385_value);
	env_t_1386 env_t_1386_value = make_env_t_1386(cam941); closure_t closure940 = make_closure(lambda1386, &env_t_1386_value);
	value_t res;
	res.number_t_value = closure936.lam(closure936.env, x0942->arr[i1], closure940.lam(closure940.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1387 {
	array_number_t cam;
} env_t_1387;
env_t_1387 make_env_t_1387(array_number_t cam) {
	env_t_1387 env;
	env.cam = cam;
	return env;
}

value_t lambda1387(env_t_1387* env947, index_t i1) {
	array_number_t cam946 = env947->cam;
	value_t res;
	res.number_t_value = cam946->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1388 {
	array_number_t x0;
	array_number_t cam;
} env_t_1388;
env_t_1388 make_env_t_1388(array_number_t x0,array_number_t cam) {
	env_t_1388 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1389;


value_t lambda1389(env_t_1389* env950, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1390 {
	array_number_t cam;
} env_t_1390;
env_t_1390 make_env_t_1390(array_number_t cam) {
	env_t_1390 env;
	env.cam = cam;
	return env;
}

value_t lambda1390(env_t_1390* env954, index_t i2) {
	array_number_t cam953 = env954->cam;
	value_t res;
	res.number_t_value = cam953->arr[(i2) + (3)];
	return res;
}
value_t lambda1388(env_t_1388* env959, index_t i1) {
	array_number_t x0958 = env959->x0;
	array_number_t cam957 = env959->cam;
	env_t_1389 env_t_1389_value = make_empty_env(); closure_t closure952 = make_closure(lambda1389, &env_t_1389_value);
	env_t_1390 env_t_1390_value = make_env_t_1390(cam957); closure_t closure956 = make_closure(lambda1390, &env_t_1390_value);
	value_t res;
	res.number_t_value = closure952.lam(closure952.env, x0958->arr[i1], closure956.lam(closure956.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1391 {
	array_number_t cam;
} env_t_1391;
env_t_1391 make_env_t_1391(array_number_t cam) {
	env_t_1391 env;
	env.cam = cam;
	return env;
}

value_t lambda1391(env_t_1391* env963, index_t i1) {
	array_number_t cam962 = env963->cam;
	value_t res;
	res.number_t_value = cam962->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1392 {
	array_number_t x0;
	array_number_t cam;
} env_t_1392;
env_t_1392 make_env_t_1392(array_number_t x0,array_number_t cam) {
	env_t_1392 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1393;


value_t lambda1393(env_t_1393* env966, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1394 {
	array_number_t cam;
} env_t_1394;
env_t_1394 make_env_t_1394(array_number_t cam) {
	env_t_1394 env;
	env.cam = cam;
	return env;
}

value_t lambda1394(env_t_1394* env970, index_t i2) {
	array_number_t cam969 = env970->cam;
	value_t res;
	res.number_t_value = cam969->arr[(i2) + (3)];
	return res;
}
value_t lambda1392(env_t_1392* env975, index_t i1) {
	array_number_t x0974 = env975->x0;
	array_number_t cam973 = env975->cam;
	env_t_1393 env_t_1393_value = make_empty_env(); closure_t closure968 = make_closure(lambda1393, &env_t_1393_value);
	env_t_1394 env_t_1394_value = make_env_t_1394(cam973); closure_t closure972 = make_closure(lambda1394, &env_t_1394_value);
	value_t res;
	res.number_t_value = closure968.lam(closure968.env, x0974->arr[i1], closure972.lam(closure972.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1395 {
	array_number_t cam;
} env_t_1395;
env_t_1395 make_env_t_1395(array_number_t cam) {
	env_t_1395 env;
	env.cam = cam;
	return env;
}

value_t lambda1395(env_t_1395* env979, index_t i1) {
	array_number_t cam978 = env979->cam;
	value_t res;
	res.number_t_value = cam978->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1396 {
	array_number_t x0;
	array_number_t cam;
} env_t_1396;
env_t_1396 make_env_t_1396(array_number_t x0,array_number_t cam) {
	env_t_1396 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1397;


value_t lambda1397(env_t_1397* env982, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1398 {
	array_number_t cam;
} env_t_1398;
env_t_1398 make_env_t_1398(array_number_t cam) {
	env_t_1398 env;
	env.cam = cam;
	return env;
}

value_t lambda1398(env_t_1398* env986, index_t i2) {
	array_number_t cam985 = env986->cam;
	value_t res;
	res.number_t_value = cam985->arr[(i2) + (3)];
	return res;
}
value_t lambda1396(env_t_1396* env991, index_t i1) {
	array_number_t x0990 = env991->x0;
	array_number_t cam989 = env991->cam;
	env_t_1397 env_t_1397_value = make_empty_env(); closure_t closure984 = make_closure(lambda1397, &env_t_1397_value);
	env_t_1398 env_t_1398_value = make_env_t_1398(cam989); closure_t closure988 = make_closure(lambda1398, &env_t_1398_value);
	value_t res;
	res.number_t_value = closure984.lam(closure984.env, x0990->arr[i1], closure988.lam(closure988.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1399 {
	array_number_t cam;
} env_t_1399;
env_t_1399 make_env_t_1399(array_number_t cam) {
	env_t_1399 env;
	env.cam = cam;
	return env;
}

value_t lambda1399(env_t_1399* env995, index_t i1) {
	array_number_t cam994 = env995->cam;
	value_t res;
	res.number_t_value = cam994->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1400 {
	array_number_t x0;
	array_number_t cam;
} env_t_1400;
env_t_1400 make_env_t_1400(array_number_t x0,array_number_t cam) {
	env_t_1400 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1401;


value_t lambda1401(env_t_1401* env998, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1402 {
	array_number_t cam;
} env_t_1402;
env_t_1402 make_env_t_1402(array_number_t cam) {
	env_t_1402 env;
	env.cam = cam;
	return env;
}

value_t lambda1402(env_t_1402* env1002, index_t i2) {
	array_number_t cam1001 = env1002->cam;
	value_t res;
	res.number_t_value = cam1001->arr[(i2) + (3)];
	return res;
}
value_t lambda1400(env_t_1400* env1007, index_t i1) {
	array_number_t x01006 = env1007->x0;
	array_number_t cam1005 = env1007->cam;
	env_t_1401 env_t_1401_value = make_empty_env(); closure_t closure1000 = make_closure(lambda1401, &env_t_1401_value);
	env_t_1402 env_t_1402_value = make_env_t_1402(cam1005); closure_t closure1004 = make_closure(lambda1402, &env_t_1402_value);
	value_t res;
	res.number_t_value = closure1000.lam(closure1000.env, x01006->arr[i1], closure1004.lam(closure1004.env, i1).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1403 {
	array_number_t cam;
} env_t_1403;
env_t_1403 make_env_t_1403(array_number_t cam) {
	env_t_1403 env;
	env.cam = cam;
	return env;
}

value_t lambda1403(env_t_1403* env1011, index_t i1) {
	array_number_t cam1010 = env1011->cam;
	value_t res;
	res.number_t_value = cam1010->arr[(i1) + (0)];
	return res;
}
typedef struct env_t_1404 {
	array_number_t x0;
	array_number_t cam;
} env_t_1404;
env_t_1404 make_env_t_1404(array_number_t x0,array_number_t cam) {
	env_t_1404 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1405;


value_t lambda1405(env_t_1405* env1014, number_t x2, number_t y0) {
	
	value_t res;
	res.number_t_value = (x2) - (y0);
	return res;
}
typedef struct env_t_1406 {
	array_number_t cam;
} env_t_1406;
env_t_1406 make_env_t_1406(array_number_t cam) {
	env_t_1406 env;
	env.cam = cam;
	return env;
}

value_t lambda1406(env_t_1406* env1018, index_t i2) {
	array_number_t cam1017 = env1018->cam;
	value_t res;
	res.number_t_value = cam1017->arr[(i2) + (3)];
	return res;
}
value_t lambda1404(env_t_1404* env1023, index_t i1) {
	array_number_t x01022 = env1023->x0;
	array_number_t cam1021 = env1023->cam;
	env_t_1405 env_t_1405_value = make_empty_env(); closure_t closure1016 = make_closure(lambda1405, &env_t_1405_value);
	env_t_1406 env_t_1406_value = make_env_t_1406(cam1021); closure_t closure1020 = make_closure(lambda1406, &env_t_1406_value);
	value_t res;
	res.number_t_value = closure1016.lam(closure1016.env, x01022->arr[i1], closure1020.lam(closure1020.env, i1).number_t_value).number_t_value;
	return res;
}
typedef empty_env_t env_t_1407;


value_t lambda1407(env_t_1407* env1027, number_t x2, number_t y1) {
	
	value_t res;
	res.number_t_value = (x2) + (y1);
	return res;
}
typedef struct env_t_1408 {
	array_number_t x0;
	array_number_t cam;
} env_t_1408;
env_t_1408 make_env_t_1408(array_number_t x0,array_number_t cam) {
	env_t_1408 env;
	env.x0 = x0;
	env.cam = cam;
	return env;
}
typedef empty_env_t env_t_1409;


value_t lambda1409(env_t_1409* env1030, number_t x2, number_t y1) {
	
	value_t res;
	res.number_t_value = (x2) - (y1);
	return res;
}
typedef struct env_t_1410 {
	array_number_t cam;
} env_t_1410;
env_t_1410 make_env_t_1410(array_number_t cam) {
	env_t_1410 env;
	env.cam = cam;
	return env;
}

value_t lambda1410(env_t_1410* env1034, index_t i3) {
	array_number_t cam1033 = env1034->cam;
	value_t res;
	res.number_t_value = cam1033->arr[(i3) + (3)];
	return res;
}
value_t lambda1408(env_t_1408* env1039, index_t i2) {
	array_number_t x01038 = env1039->x0;
	array_number_t cam1037 = env1039->cam;
	env_t_1409 env_t_1409_value = make_empty_env(); closure_t closure1032 = make_closure(lambda1409, &env_t_1409_value);
	env_t_1410 env_t_1410_value = make_env_t_1410(cam1037); closure_t closure1036 = make_closure(lambda1410, &env_t_1410_value);
	value_t res;
	res.number_t_value = closure1032.lam(closure1032.env, x01038->arr[i2], closure1036.lam(closure1036.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1411 {
	number_t y0;
} env_t_1411;
env_t_1411 make_env_t_1411(number_t y0) {
	env_t_1411 env;
	env.y0 = y0;
	return env;
}

value_t lambda1411(env_t_1411* env1046, number_t a) {
	number_t y01045 = env1046->y0;
	value_t res;
	res.number_t_value = (a) * (y01045);
	return res;
}
typedef struct env_t_1412 {
	array_number_t Xcam;
} env_t_1412;
env_t_1412 make_env_t_1412(array_number_t Xcam) {
	env_t_1412 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1412(env_t_1412* env1050, index_t i2) {
	array_number_t Xcam1049 = env1050->Xcam;
	value_t res;
	res.number_t_value = Xcam1049->arr[(i2) + (0)];
	return res;
}
typedef empty_env_t env_t_1413;


value_t lambda1413(env_t_1413* env1054, number_t x10) {
	
	value_t res;
	res.number_t_value = (x10) * (x10);
	return res;
}
typedef struct env_t_1414 {
	number_t y0;
	array_number_t Xcam;
} env_t_1414;
env_t_1414 make_env_t_1414(number_t y0,array_number_t Xcam) {
	env_t_1414 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1415 {
	number_t y0;
} env_t_1415;
env_t_1415 make_env_t_1415(number_t y0) {
	env_t_1415 env;
	env.y0 = y0;
	return env;
}

value_t lambda1415(env_t_1415* env1058, number_t a) {
	number_t y01057 = env1058->y0;
	value_t res;
	res.number_t_value = (a) * (y01057);
	return res;
}
typedef struct env_t_1416 {
	array_number_t Xcam;
} env_t_1416;
env_t_1416 make_env_t_1416(array_number_t Xcam) {
	env_t_1416 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1416(env_t_1416* env1062, index_t i3) {
	array_number_t Xcam1061 = env1062->Xcam;
	value_t res;
	res.number_t_value = Xcam1061->arr[(i3) + (0)];
	return res;
}
value_t lambda1414(env_t_1414* env1067, index_t i2) {
	number_t y01066 = env1067->y0;
	array_number_t Xcam1065 = env1067->Xcam;
	env_t_1415 env_t_1415_value = make_env_t_1415(y01066); closure_t closure1060 = make_closure(lambda1415, &env_t_1415_value);
	env_t_1416 env_t_1416_value = make_env_t_1416(Xcam1065); closure_t closure1064 = make_closure(lambda1416, &env_t_1416_value);
	value_t res;
	res.number_t_value = closure1060.lam(closure1060.env, closure1064.lam(closure1064.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1417 {
	array_number_t cam;
} env_t_1417;
env_t_1417 make_env_t_1417(array_number_t cam) {
	env_t_1417 env;
	env.cam = cam;
	return env;
}

value_t lambda1417(env_t_1417* env1073, index_t i1) {
	array_number_t cam1072 = env1073->cam;
	value_t res;
	res.number_t_value = cam1072->arr[(i1) + (9)];
	return res;
}
typedef struct env_t_1418 {
	array_number_t cam;
} env_t_1418;
env_t_1418 make_env_t_1418(array_number_t cam) {
	env_t_1418 env;
	env.cam = cam;
	return env;
}

value_t lambda1418(env_t_1418* env1077, index_t i1) {
	array_number_t cam1076 = env1077->cam;
	value_t res;
	res.number_t_value = cam1076->arr[(i1) + (9)];
	return res;
}
typedef struct env_t_1419 {
	number_t L;
} env_t_1419;
env_t_1419 make_env_t_1419(number_t L) {
	env_t_1419 env;
	env.L = L;
	return env;
}

value_t lambda1419(env_t_1419* env1081, number_t a) {
	number_t L1080 = env1081->L;
	value_t res;
	res.number_t_value = (a) * (L1080);
	return res;
}
typedef struct env_t_1420 {
	number_t y0;
	array_number_t Xcam;
} env_t_1420;
env_t_1420 make_env_t_1420(number_t y0,array_number_t Xcam) {
	env_t_1420 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1421 {
	number_t y0;
} env_t_1421;
env_t_1421 make_env_t_1421(number_t y0) {
	env_t_1421 env;
	env.y0 = y0;
	return env;
}

value_t lambda1421(env_t_1421* env1085, number_t a) {
	number_t y01084 = env1085->y0;
	value_t res;
	res.number_t_value = (a) * (y01084);
	return res;
}
typedef struct env_t_1422 {
	array_number_t Xcam;
} env_t_1422;
env_t_1422 make_env_t_1422(array_number_t Xcam) {
	env_t_1422 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1422(env_t_1422* env1089, index_t i3) {
	array_number_t Xcam1088 = env1089->Xcam;
	value_t res;
	res.number_t_value = Xcam1088->arr[(i3) + (0)];
	return res;
}
value_t lambda1420(env_t_1420* env1094, index_t i2) {
	number_t y01093 = env1094->y0;
	array_number_t Xcam1092 = env1094->Xcam;
	env_t_1421 env_t_1421_value = make_env_t_1421(y01093); closure_t closure1087 = make_closure(lambda1421, &env_t_1421_value);
	env_t_1422 env_t_1422_value = make_env_t_1422(Xcam1092); closure_t closure1091 = make_closure(lambda1422, &env_t_1422_value);
	value_t res;
	res.number_t_value = closure1087.lam(closure1087.env, closure1091.lam(closure1091.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1423 {
	number_t y1;
} env_t_1423;
env_t_1423 make_env_t_1423(number_t y1) {
	env_t_1423 env;
	env.y1 = y1;
	return env;
}

value_t lambda1423(env_t_1423* env1100, number_t a) {
	number_t y11099 = env1100->y1;
	value_t res;
	res.number_t_value = (a) * (y11099);
	return res;
}
typedef struct env_t_1424 {
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1424;
env_t_1424 make_env_t_1424(number_t y0,array_number_t Xcam,number_t L) {
	env_t_1424 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1425 {
	number_t L;
} env_t_1425;
env_t_1425 make_env_t_1425(number_t L) {
	env_t_1425 env;
	env.L = L;
	return env;
}

value_t lambda1425(env_t_1425* env1104, number_t a) {
	number_t L1103 = env1104->L;
	value_t res;
	res.number_t_value = (a) * (L1103);
	return res;
}
typedef struct env_t_1426 {
	number_t y0;
	array_number_t Xcam;
} env_t_1426;
env_t_1426 make_env_t_1426(number_t y0,array_number_t Xcam) {
	env_t_1426 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1427 {
	number_t y0;
} env_t_1427;
env_t_1427 make_env_t_1427(number_t y0) {
	env_t_1427 env;
	env.y0 = y0;
	return env;
}

value_t lambda1427(env_t_1427* env1108, number_t a) {
	number_t y01107 = env1108->y0;
	value_t res;
	res.number_t_value = (a) * (y01107);
	return res;
}
typedef struct env_t_1428 {
	array_number_t Xcam;
} env_t_1428;
env_t_1428 make_env_t_1428(array_number_t Xcam) {
	env_t_1428 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1428(env_t_1428* env1112, index_t i4) {
	array_number_t Xcam1111 = env1112->Xcam;
	value_t res;
	res.number_t_value = Xcam1111->arr[(i4) + (0)];
	return res;
}
value_t lambda1426(env_t_1426* env1117, index_t i3) {
	number_t y01116 = env1117->y0;
	array_number_t Xcam1115 = env1117->Xcam;
	env_t_1427 env_t_1427_value = make_env_t_1427(y01116); closure_t closure1110 = make_closure(lambda1427, &env_t_1427_value);
	env_t_1428 env_t_1428_value = make_env_t_1428(Xcam1115); closure_t closure1114 = make_closure(lambda1428, &env_t_1428_value);
	value_t res;
	res.number_t_value = closure1110.lam(closure1110.env, closure1114.lam(closure1114.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1424(env_t_1424* env1123, index_t i2) {
	number_t y01122 = env1123->y0;
	array_number_t Xcam1121 = env1123->Xcam;
	number_t L1120 = env1123->L;
	env_t_1425 env_t_1425_value = make_env_t_1425(L1120); closure_t closure1106 = make_closure(lambda1425, &env_t_1425_value);
	env_t_1426 env_t_1426_value = make_env_t_1426(y01122,Xcam1121); closure_t closure1119 = make_closure(lambda1426, &env_t_1426_value);
	value_t res;
	res.number_t_value = closure1106.lam(closure1106.env, closure1119.lam(closure1119.env, i2).number_t_value).number_t_value;
	return res;
}
typedef empty_env_t env_t_1429;


value_t lambda1429(env_t_1429* env1127, number_t x4, number_t y3) {
	
	value_t res;
	res.number_t_value = (x4) + (y3);
	return res;
}
typedef struct env_t_1430 {
	array_number_t cam;
} env_t_1430;
env_t_1430 make_env_t_1430(array_number_t cam) {
	env_t_1430 env;
	env.cam = cam;
	return env;
}

value_t lambda1430(env_t_1430* env1131, index_t i2) {
	array_number_t cam1130 = env1131->cam;
	value_t res;
	res.number_t_value = cam1130->arr[(i2) + (7)];
	return res;
}
typedef struct env_t_1431 {
	number_t y1;
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1431;
env_t_1431 make_env_t_1431(number_t y1,number_t y0,array_number_t Xcam,number_t L) {
	env_t_1431 env;
	env.y1 = y1;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1432 {
	number_t y1;
} env_t_1432;
env_t_1432 make_env_t_1432(number_t y1) {
	env_t_1432 env;
	env.y1 = y1;
	return env;
}

value_t lambda1432(env_t_1432* env1135, number_t a) {
	number_t y11134 = env1135->y1;
	value_t res;
	res.number_t_value = (a) * (y11134);
	return res;
}
typedef struct env_t_1433 {
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1433;
env_t_1433 make_env_t_1433(number_t y0,array_number_t Xcam,number_t L) {
	env_t_1433 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1434 {
	number_t L;
} env_t_1434;
env_t_1434 make_env_t_1434(number_t L) {
	env_t_1434 env;
	env.L = L;
	return env;
}

value_t lambda1434(env_t_1434* env1139, number_t a) {
	number_t L1138 = env1139->L;
	value_t res;
	res.number_t_value = (a) * (L1138);
	return res;
}
typedef struct env_t_1435 {
	number_t y0;
	array_number_t Xcam;
} env_t_1435;
env_t_1435 make_env_t_1435(number_t y0,array_number_t Xcam) {
	env_t_1435 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1436 {
	number_t y0;
} env_t_1436;
env_t_1436 make_env_t_1436(number_t y0) {
	env_t_1436 env;
	env.y0 = y0;
	return env;
}

value_t lambda1436(env_t_1436* env1143, number_t a) {
	number_t y01142 = env1143->y0;
	value_t res;
	res.number_t_value = (a) * (y01142);
	return res;
}
typedef struct env_t_1437 {
	array_number_t Xcam;
} env_t_1437;
env_t_1437 make_env_t_1437(array_number_t Xcam) {
	env_t_1437 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1437(env_t_1437* env1147, index_t i5) {
	array_number_t Xcam1146 = env1147->Xcam;
	value_t res;
	res.number_t_value = Xcam1146->arr[(i5) + (0)];
	return res;
}
value_t lambda1435(env_t_1435* env1152, index_t i4) {
	number_t y01151 = env1152->y0;
	array_number_t Xcam1150 = env1152->Xcam;
	env_t_1436 env_t_1436_value = make_env_t_1436(y01151); closure_t closure1145 = make_closure(lambda1436, &env_t_1436_value);
	env_t_1437 env_t_1437_value = make_env_t_1437(Xcam1150); closure_t closure1149 = make_closure(lambda1437, &env_t_1437_value);
	value_t res;
	res.number_t_value = closure1145.lam(closure1145.env, closure1149.lam(closure1149.env, i4).number_t_value).number_t_value;
	return res;
}
value_t lambda1433(env_t_1433* env1158, index_t i3) {
	number_t y01157 = env1158->y0;
	array_number_t Xcam1156 = env1158->Xcam;
	number_t L1155 = env1158->L;
	env_t_1434 env_t_1434_value = make_env_t_1434(L1155); closure_t closure1141 = make_closure(lambda1434, &env_t_1434_value);
	env_t_1435 env_t_1435_value = make_env_t_1435(y01157,Xcam1156); closure_t closure1154 = make_closure(lambda1435, &env_t_1435_value);
	value_t res;
	res.number_t_value = closure1141.lam(closure1141.env, closure1154.lam(closure1154.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1431(env_t_1431* env1165, index_t i2) {
	number_t y11164 = env1165->y1;
	number_t y01163 = env1165->y0;
	array_number_t Xcam1162 = env1165->Xcam;
	number_t L1161 = env1165->L;
	env_t_1432 env_t_1432_value = make_env_t_1432(y11164); closure_t closure1137 = make_closure(lambda1432, &env_t_1432_value);
	env_t_1433 env_t_1433_value = make_env_t_1433(y01163,Xcam1162,L1161); closure_t closure1160 = make_closure(lambda1433, &env_t_1433_value);
	value_t res;
	res.number_t_value = closure1137.lam(closure1137.env, closure1160.lam(closure1160.env, i2).number_t_value).number_t_value;
	return res;
}
typedef empty_env_t env_t_1438;


value_t lambda1438(env_t_1438* env1169, number_t x5, number_t y3) {
	
	value_t res;
	res.number_t_value = (x5) - (y3);
	return res;
}
typedef struct env_t_1439 {
	number_t y1;
	number_t y0;
	array_number_t cam;
	array_number_t Xcam;
	number_t L;
} env_t_1439;
env_t_1439 make_env_t_1439(number_t y1,number_t y0,array_number_t cam,array_number_t Xcam,number_t L) {
	env_t_1439 env;
	env.y1 = y1;
	env.y0 = y0;
	env.cam = cam;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef empty_env_t env_t_1440;


value_t lambda1440(env_t_1440* env1172, number_t x5, number_t y3) {
	
	value_t res;
	res.number_t_value = (x5) + (y3);
	return res;
}
typedef struct env_t_1441 {
	array_number_t cam;
} env_t_1441;
env_t_1441 make_env_t_1441(array_number_t cam) {
	env_t_1441 env;
	env.cam = cam;
	return env;
}

value_t lambda1441(env_t_1441* env1176, index_t i3) {
	array_number_t cam1175 = env1176->cam;
	value_t res;
	res.number_t_value = cam1175->arr[(i3) + (7)];
	return res;
}
typedef struct env_t_1442 {
	number_t y1;
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1442;
env_t_1442 make_env_t_1442(number_t y1,number_t y0,array_number_t Xcam,number_t L) {
	env_t_1442 env;
	env.y1 = y1;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1443 {
	number_t y1;
} env_t_1443;
env_t_1443 make_env_t_1443(number_t y1) {
	env_t_1443 env;
	env.y1 = y1;
	return env;
}

value_t lambda1443(env_t_1443* env1180, number_t a) {
	number_t y11179 = env1180->y1;
	value_t res;
	res.number_t_value = (a) * (y11179);
	return res;
}
typedef struct env_t_1444 {
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1444;
env_t_1444 make_env_t_1444(number_t y0,array_number_t Xcam,number_t L) {
	env_t_1444 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1445 {
	number_t L;
} env_t_1445;
env_t_1445 make_env_t_1445(number_t L) {
	env_t_1445 env;
	env.L = L;
	return env;
}

value_t lambda1445(env_t_1445* env1184, number_t a) {
	number_t L1183 = env1184->L;
	value_t res;
	res.number_t_value = (a) * (L1183);
	return res;
}
typedef struct env_t_1446 {
	number_t y0;
	array_number_t Xcam;
} env_t_1446;
env_t_1446 make_env_t_1446(number_t y0,array_number_t Xcam) {
	env_t_1446 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1447 {
	number_t y0;
} env_t_1447;
env_t_1447 make_env_t_1447(number_t y0) {
	env_t_1447 env;
	env.y0 = y0;
	return env;
}

value_t lambda1447(env_t_1447* env1188, number_t a) {
	number_t y01187 = env1188->y0;
	value_t res;
	res.number_t_value = (a) * (y01187);
	return res;
}
typedef struct env_t_1448 {
	array_number_t Xcam;
} env_t_1448;
env_t_1448 make_env_t_1448(array_number_t Xcam) {
	env_t_1448 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1448(env_t_1448* env1192, index_t i6) {
	array_number_t Xcam1191 = env1192->Xcam;
	value_t res;
	res.number_t_value = Xcam1191->arr[(i6) + (0)];
	return res;
}
value_t lambda1446(env_t_1446* env1197, index_t i5) {
	number_t y01196 = env1197->y0;
	array_number_t Xcam1195 = env1197->Xcam;
	env_t_1447 env_t_1447_value = make_env_t_1447(y01196); closure_t closure1190 = make_closure(lambda1447, &env_t_1447_value);
	env_t_1448 env_t_1448_value = make_env_t_1448(Xcam1195); closure_t closure1194 = make_closure(lambda1448, &env_t_1448_value);
	value_t res;
	res.number_t_value = closure1190.lam(closure1190.env, closure1194.lam(closure1194.env, i5).number_t_value).number_t_value;
	return res;
}
value_t lambda1444(env_t_1444* env1203, index_t i4) {
	number_t y01202 = env1203->y0;
	array_number_t Xcam1201 = env1203->Xcam;
	number_t L1200 = env1203->L;
	env_t_1445 env_t_1445_value = make_env_t_1445(L1200); closure_t closure1186 = make_closure(lambda1445, &env_t_1445_value);
	env_t_1446 env_t_1446_value = make_env_t_1446(y01202,Xcam1201); closure_t closure1199 = make_closure(lambda1446, &env_t_1446_value);
	value_t res;
	res.number_t_value = closure1186.lam(closure1186.env, closure1199.lam(closure1199.env, i4).number_t_value).number_t_value;
	return res;
}
value_t lambda1442(env_t_1442* env1210, index_t i3) {
	number_t y11209 = env1210->y1;
	number_t y01208 = env1210->y0;
	array_number_t Xcam1207 = env1210->Xcam;
	number_t L1206 = env1210->L;
	env_t_1443 env_t_1443_value = make_env_t_1443(y11209); closure_t closure1182 = make_closure(lambda1443, &env_t_1443_value);
	env_t_1444 env_t_1444_value = make_env_t_1444(y01208,Xcam1207,L1206); closure_t closure1205 = make_closure(lambda1444, &env_t_1444_value);
	value_t res;
	res.number_t_value = closure1182.lam(closure1182.env, closure1205.lam(closure1205.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1439(env_t_1439* env1218, index_t i2) {
	number_t y11217 = env1218->y1;
	number_t y01216 = env1218->y0;
	array_number_t cam1215 = env1218->cam;
	array_number_t Xcam1214 = env1218->Xcam;
	number_t L1213 = env1218->L;
	env_t_1440 env_t_1440_value = make_empty_env(); closure_t closure1174 = make_closure(lambda1440, &env_t_1440_value);
	env_t_1441 env_t_1441_value = make_env_t_1441(cam1215); closure_t closure1178 = make_closure(lambda1441, &env_t_1441_value);
	env_t_1442 env_t_1442_value = make_env_t_1442(y11217,y01216,Xcam1214,L1213); closure_t closure1212 = make_closure(lambda1442, &env_t_1442_value);
	value_t res;
	res.number_t_value = closure1174.lam(closure1174.env, closure1178.lam(closure1178.env, i2).number_t_value, closure1212.lam(closure1212.env, i2).number_t_value).number_t_value;
	return res;
}
typedef struct env_t_1449 {
	number_t w0;
} env_t_1449;
env_t_1449 make_env_t_1449(number_t w0) {
	env_t_1449 env;
	env.w0 = w0;
	return env;
}

value_t lambda1449(env_t_1449* env1223, number_t a) {
	number_t w01222 = env1223->w0;
	value_t res;
	res.number_t_value = (a) * (w01222);
	return res;
}
typedef struct env_t_1450 {
	number_t y1;
	number_t y0;
	array_number_t feat0;
	array_number_t cam;
	array_number_t Xcam;
	number_t L;
} env_t_1450;
env_t_1450 make_env_t_1450(number_t y1,number_t y0,array_number_t feat0,array_number_t cam,array_number_t Xcam,number_t L) {
	env_t_1450 env;
	env.y1 = y1;
	env.y0 = y0;
	env.feat0 = feat0;
	env.cam = cam;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef empty_env_t env_t_1451;


value_t lambda1451(env_t_1451* env1226, number_t x6, number_t y3) {
	
	value_t res;
	res.number_t_value = (x6) - (y3);
	return res;
}
typedef struct env_t_1452 {
	number_t y1;
	number_t y0;
	array_number_t cam;
	array_number_t Xcam;
	number_t L;
} env_t_1452;
env_t_1452 make_env_t_1452(number_t y1,number_t y0,array_number_t cam,array_number_t Xcam,number_t L) {
	env_t_1452 env;
	env.y1 = y1;
	env.y0 = y0;
	env.cam = cam;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef empty_env_t env_t_1453;


value_t lambda1453(env_t_1453* env1229, number_t x6, number_t y3) {
	
	value_t res;
	res.number_t_value = (x6) + (y3);
	return res;
}
typedef struct env_t_1454 {
	array_number_t cam;
} env_t_1454;
env_t_1454 make_env_t_1454(array_number_t cam) {
	env_t_1454 env;
	env.cam = cam;
	return env;
}

value_t lambda1454(env_t_1454* env1233, index_t i4) {
	array_number_t cam1232 = env1233->cam;
	value_t res;
	res.number_t_value = cam1232->arr[(i4) + (7)];
	return res;
}
typedef struct env_t_1455 {
	number_t y1;
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1455;
env_t_1455 make_env_t_1455(number_t y1,number_t y0,array_number_t Xcam,number_t L) {
	env_t_1455 env;
	env.y1 = y1;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1456 {
	number_t y1;
} env_t_1456;
env_t_1456 make_env_t_1456(number_t y1) {
	env_t_1456 env;
	env.y1 = y1;
	return env;
}

value_t lambda1456(env_t_1456* env1237, number_t a) {
	number_t y11236 = env1237->y1;
	value_t res;
	res.number_t_value = (a) * (y11236);
	return res;
}
typedef struct env_t_1457 {
	number_t y0;
	array_number_t Xcam;
	number_t L;
} env_t_1457;
env_t_1457 make_env_t_1457(number_t y0,array_number_t Xcam,number_t L) {
	env_t_1457 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	env.L = L;
	return env;
}
typedef struct env_t_1458 {
	number_t L;
} env_t_1458;
env_t_1458 make_env_t_1458(number_t L) {
	env_t_1458 env;
	env.L = L;
	return env;
}

value_t lambda1458(env_t_1458* env1241, number_t a) {
	number_t L1240 = env1241->L;
	value_t res;
	res.number_t_value = (a) * (L1240);
	return res;
}
typedef struct env_t_1459 {
	number_t y0;
	array_number_t Xcam;
} env_t_1459;
env_t_1459 make_env_t_1459(number_t y0,array_number_t Xcam) {
	env_t_1459 env;
	env.y0 = y0;
	env.Xcam = Xcam;
	return env;
}
typedef struct env_t_1460 {
	number_t y0;
} env_t_1460;
env_t_1460 make_env_t_1460(number_t y0) {
	env_t_1460 env;
	env.y0 = y0;
	return env;
}

value_t lambda1460(env_t_1460* env1245, number_t a) {
	number_t y01244 = env1245->y0;
	value_t res;
	res.number_t_value = (a) * (y01244);
	return res;
}
typedef struct env_t_1461 {
	array_number_t Xcam;
} env_t_1461;
env_t_1461 make_env_t_1461(array_number_t Xcam) {
	env_t_1461 env;
	env.Xcam = Xcam;
	return env;
}

value_t lambda1461(env_t_1461* env1249, index_t i7) {
	array_number_t Xcam1248 = env1249->Xcam;
	value_t res;
	res.number_t_value = Xcam1248->arr[(i7) + (0)];
	return res;
}
value_t lambda1459(env_t_1459* env1254, index_t i6) {
	number_t y01253 = env1254->y0;
	array_number_t Xcam1252 = env1254->Xcam;
	env_t_1460 env_t_1460_value = make_env_t_1460(y01253); closure_t closure1247 = make_closure(lambda1460, &env_t_1460_value);
	env_t_1461 env_t_1461_value = make_env_t_1461(Xcam1252); closure_t closure1251 = make_closure(lambda1461, &env_t_1461_value);
	value_t res;
	res.number_t_value = closure1247.lam(closure1247.env, closure1251.lam(closure1251.env, i6).number_t_value).number_t_value;
	return res;
}
value_t lambda1457(env_t_1457* env1260, index_t i5) {
	number_t y01259 = env1260->y0;
	array_number_t Xcam1258 = env1260->Xcam;
	number_t L1257 = env1260->L;
	env_t_1458 env_t_1458_value = make_env_t_1458(L1257); closure_t closure1243 = make_closure(lambda1458, &env_t_1458_value);
	env_t_1459 env_t_1459_value = make_env_t_1459(y01259,Xcam1258); closure_t closure1256 = make_closure(lambda1459, &env_t_1459_value);
	value_t res;
	res.number_t_value = closure1243.lam(closure1243.env, closure1256.lam(closure1256.env, i5).number_t_value).number_t_value;
	return res;
}
value_t lambda1455(env_t_1455* env1267, index_t i4) {
	number_t y11266 = env1267->y1;
	number_t y01265 = env1267->y0;
	array_number_t Xcam1264 = env1267->Xcam;
	number_t L1263 = env1267->L;
	env_t_1456 env_t_1456_value = make_env_t_1456(y11266); closure_t closure1239 = make_closure(lambda1456, &env_t_1456_value);
	env_t_1457 env_t_1457_value = make_env_t_1457(y01265,Xcam1264,L1263); closure_t closure1262 = make_closure(lambda1457, &env_t_1457_value);
	value_t res;
	res.number_t_value = closure1239.lam(closure1239.env, closure1262.lam(closure1262.env, i4).number_t_value).number_t_value;
	return res;
}
value_t lambda1452(env_t_1452* env1275, index_t i3) {
	number_t y11274 = env1275->y1;
	number_t y01273 = env1275->y0;
	array_number_t cam1272 = env1275->cam;
	array_number_t Xcam1271 = env1275->Xcam;
	number_t L1270 = env1275->L;
	env_t_1453 env_t_1453_value = make_empty_env(); closure_t closure1231 = make_closure(lambda1453, &env_t_1453_value);
	env_t_1454 env_t_1454_value = make_env_t_1454(cam1272); closure_t closure1235 = make_closure(lambda1454, &env_t_1454_value);
	env_t_1455 env_t_1455_value = make_env_t_1455(y11274,y01273,Xcam1271,L1270); closure_t closure1269 = make_closure(lambda1455, &env_t_1455_value);
	value_t res;
	res.number_t_value = closure1231.lam(closure1231.env, closure1235.lam(closure1235.env, i3).number_t_value, closure1269.lam(closure1269.env, i3).number_t_value).number_t_value;
	return res;
}
value_t lambda1450(env_t_1450* env1284, index_t i2) {
	number_t y11283 = env1284->y1;
	number_t y01282 = env1284->y0;
	array_number_t feat01281 = env1284->feat0;
	array_number_t cam1280 = env1284->cam;
	array_number_t Xcam1279 = env1284->Xcam;
	number_t L1278 = env1284->L;
	env_t_1451 env_t_1451_value = make_empty_env(); closure_t closure1228 = make_closure(lambda1451, &env_t_1451_value);
	env_t_1452 env_t_1452_value = make_env_t_1452(y11283,y01282,cam1280,Xcam1279,L1278); closure_t closure1277 = make_closure(lambda1452, &env_t_1452_value);
	value_t res;
	res.number_t_value = closure1228.lam(closure1228.env, closure1277.lam(closure1277.env, i2).number_t_value, feat01281->arr[i2]).number_t_value;
	return res;
}
value_t lambda1301(env_t_1301* env1293, number_t i0) {
	array_array_number_t x1292 = env1293->x;
	array_number_t w1291 = env1293->w;
	array_array_number_t obs1290 = env1293->obs;
	array_array_number_t feat1289 = env1293->feat;
	array_array_number_t cams1288 = env1293->cams;
	array_number_t cam = cams1288->arr[(int)(obs1290->arr[(int)(i0)]->arr[0])];
	array_number_t x0 = x1292->arr[(int)(obs1290->arr[(int)(i0)]->arr[1])];
	number_t w0 = w1291->arr[(int)(i0)];
	array_number_t feat0 = feat1289->arr[(int)(i0)];
	array_number_t macroDef573 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef573->length=(((0) + (2)) - (0)) + (1);
	macroDef573->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef573->length; i1++){
			
			macroDef573->arr[i1] = cam->arr[(i1) + (0)];;
		}
	array_number_t rot = macroDef573;
	array_number_t macroDef574 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef574->length=(((3) + (2)) - (3)) + (1);
	macroDef574->arr = (number_t*)storage_alloc(sizeof(number_t) * (((3) + (2)) - (3)) + (1));
		for(int i1 = 0; i1 < macroDef574->length; i1++){
			
			macroDef574->arr[i1] = cam->arr[(i1) + (3)];;
		}
	array_number_t y = macroDef574;
	card_t macroDef575 = x0->length;
	array_number_t macroDef583 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef583->length=macroDef575;
	macroDef583->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef575);
		for(int i1 = 0; i1 < macroDef583->length; i1++){
			env_t_1302 env_t_1302_value = make_empty_env(); closure_t closure578 = make_closure(lambda1302, &env_t_1302_value);
			env_t_1303 env_t_1303_value = make_env_t_1303(cam); closure_t closure582 = make_closure(lambda1303, &env_t_1303_value);
			macroDef583->arr[i1] = closure578.lam(closure578.env, x0->arr[i1], closure582.lam(closure582.env, i1).number_t_value).number_t_value;;
		}
	array_number_t x1 = macroDef583;
	array_number_t macroDef591 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef591->length=(((0) + (2)) - (0)) + (1);
	macroDef591->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef591->length; i1++){
			env_t_1304 env_t_1304_value = make_empty_env(); closure_t closure586 = make_closure(lambda1304, &env_t_1304_value);
			env_t_1305 env_t_1305_value = make_env_t_1305(cam); closure_t closure590 = make_closure(lambda1305, &env_t_1305_value);
			macroDef591->arr[i1] = closure586.lam(closure586.env, closure590.lam(closure590.env, i1).number_t_value).number_t_value;;
		}
	array_number_t v = macroDef591;
	number_t macroDef592 = 0;
	for(int cur_idx = 0; cur_idx < v->length; cur_idx++){
		number_t cur = v->arr[cur_idx];
		
		macroDef592 = (macroDef592) + (cur);;
	}
	number_t sqtheta = macroDef592;
	array_number_t Xcam = 0;
	if((sqtheta) != (0)) {
		number_t theta = sqrt(sqtheta);
		number_t costheta = cos(theta);
		number_t sintheta = sin(theta);
		number_t theta_inv = (1) / (theta);
		array_number_t macroDef601 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef601->length=(((0) + (2)) - (0)) + (1);
	macroDef601->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef601->length; i1++){
			env_t_1306 env_t_1306_value = make_env_t_1306(theta_inv); closure_t closure596 = make_closure(lambda1306, &env_t_1306_value);
			env_t_1307 env_t_1307_value = make_env_t_1307(cam); closure_t closure600 = make_closure(lambda1307, &env_t_1307_value);
			macroDef601->arr[i1] = closure596.lam(closure596.env, closure600.lam(closure600.env, i1).number_t_value).number_t_value;;
		}
		array_number_t w1 = macroDef601;
		env_t_1308 env_t_1308_value = make_env_t_1308(theta_inv,cam); closure_t closure614 = make_closure(lambda1308, &env_t_1308_value);
		env_t_1311 env_t_1311_value = make_env_t_1311(x0,cam); closure_t closure626 = make_closure(lambda1311, &env_t_1311_value);
		env_t_1314 env_t_1314_value = make_env_t_1314(theta_inv,cam); closure_t closure639 = make_closure(lambda1314, &env_t_1314_value);
		env_t_1317 env_t_1317_value = make_env_t_1317(x0,cam); closure_t closure651 = make_closure(lambda1317, &env_t_1317_value);
		env_t_1320 env_t_1320_value = make_env_t_1320(theta_inv,cam); closure_t closure664 = make_closure(lambda1320, &env_t_1320_value);
		env_t_1323 env_t_1323_value = make_env_t_1323(x0,cam); closure_t closure676 = make_closure(lambda1323, &env_t_1323_value);
		env_t_1326 env_t_1326_value = make_env_t_1326(theta_inv,cam); closure_t closure689 = make_closure(lambda1326, &env_t_1326_value);
		env_t_1329 env_t_1329_value = make_env_t_1329(x0,cam); closure_t closure701 = make_closure(lambda1329, &env_t_1329_value);
		env_t_1332 env_t_1332_value = make_env_t_1332(theta_inv,cam); closure_t closure714 = make_closure(lambda1332, &env_t_1332_value);
		env_t_1335 env_t_1335_value = make_env_t_1335(x0,cam); closure_t closure726 = make_closure(lambda1335, &env_t_1335_value);
		env_t_1338 env_t_1338_value = make_env_t_1338(theta_inv,cam); closure_t closure739 = make_closure(lambda1338, &env_t_1338_value);
		env_t_1341 env_t_1341_value = make_env_t_1341(x0,cam); closure_t closure751 = make_closure(lambda1341, &env_t_1341_value);
		array_number_t w_cross_X = (array_number_t)storage_alloc(sizeof(int) * 2);
	w_cross_X->length=3;
	w_cross_X->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	w_cross_X->arr[0] = ((closure614.lam(closure614.env, 1).number_t_value) * (closure626.lam(closure626.env, 2).number_t_value)) - ((closure639.lam(closure639.env, 2).number_t_value) * (closure651.lam(closure651.env, 1).number_t_value));
	w_cross_X->arr[1] = ((closure664.lam(closure664.env, 2).number_t_value) * (closure676.lam(closure676.env, 0).number_t_value)) - ((closure689.lam(closure689.env, 0).number_t_value) * (closure701.lam(closure701.env, 2).number_t_value));
	w_cross_X->arr[2] = ((closure714.lam(closure714.env, 0).number_t_value) * (closure726.lam(closure726.env, 1).number_t_value)) - ((closure739.lam(closure739.env, 1).number_t_value) * (closure751.lam(closure751.env, 0).number_t_value));;
		array_number_t macroDef780 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef780->length=(((0) + (2)) - (0)) + (1);
	macroDef780->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef780->length; i1++){
			env_t_1344 env_t_1344_value = make_empty_env(); closure_t closure754 = make_closure(lambda1344, &env_t_1344_value);
			env_t_1345 env_t_1345_value = make_env_t_1345(theta_inv,cam); closure_t closure767 = make_closure(lambda1345, &env_t_1345_value);
			env_t_1348 env_t_1348_value = make_env_t_1348(x0,cam); closure_t closure779 = make_closure(lambda1348, &env_t_1348_value);
			macroDef780->arr[i1] = closure754.lam(closure754.env, closure767.lam(closure767.env, i1).number_t_value, closure779.lam(closure779.env, i1).number_t_value).number_t_value;;
		}
		array_number_t v0 = macroDef780;
		number_t macroDef781 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef781 = (macroDef781) + (cur);;
	}
		number_t tmp = (macroDef781) * ((1) - (costheta));
		card_t macroDef782 = x0->length;
		array_number_t macroDef799 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef799->length=macroDef782;
	macroDef799->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef782);
		for(int i1 = 0; i1 < macroDef799->length; i1++){
			env_t_1351 env_t_1351_value = make_env_t_1351(costheta); closure_t closure786 = make_closure(lambda1351, &env_t_1351_value);
			env_t_1352 env_t_1352_value = make_env_t_1352(x0,cam); closure_t closure798 = make_closure(lambda1352, &env_t_1352_value);
			macroDef799->arr[i1] = closure786.lam(closure786.env, closure798.lam(closure798.env, i1).number_t_value).number_t_value;;
		}
		array_number_t v1 = macroDef799;
		card_t macroDef800 = w_cross_X->length;
		array_number_t macroDef805 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef805->length=macroDef800;
	macroDef805->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef800);
		for(int i1 = 0; i1 < macroDef805->length; i1++){
			env_t_1355 env_t_1355_value = make_env_t_1355(sintheta); closure_t closure804 = make_closure(lambda1355, &env_t_1355_value);
			macroDef805->arr[i1] = closure804.lam(closure804.env, w_cross_X->arr[i1]).number_t_value;;
		}
		array_number_t v2 = macroDef805;
		card_t macroDef806 = x0->length;
		array_number_t macroDef841 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef841->length=macroDef806;
	macroDef841->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef806);
		for(int i1 = 0; i1 < macroDef841->length; i1++){
			env_t_1356 env_t_1356_value = make_empty_env(); closure_t closure809 = make_closure(lambda1356, &env_t_1356_value);
			env_t_1357 env_t_1357_value = make_env_t_1357(x0,costheta,cam); closure_t closure831 = make_closure(lambda1357, &env_t_1357_value);
			env_t_1362 env_t_1362_value = make_env_t_1362(w_cross_X,sintheta); closure_t closure840 = make_closure(lambda1362, &env_t_1362_value);
			macroDef841->arr[i1] = closure809.lam(closure809.env, closure831.lam(closure831.env, i1).number_t_value, closure840.lam(closure840.env, i1).number_t_value).number_t_value;;
		}
		array_number_t x2 = macroDef841;
		array_number_t macroDef859 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef859->length=(((0) + (2)) - (0)) + (1);
	macroDef859->arr = (number_t*)storage_alloc(sizeof(number_t) * (((0) + (2)) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef859->length; i1++){
			env_t_1364 env_t_1364_value = make_env_t_1364(tmp); closure_t closure845 = make_closure(lambda1364, &env_t_1364_value);
			env_t_1365 env_t_1365_value = make_env_t_1365(theta_inv,cam); closure_t closure858 = make_closure(lambda1365, &env_t_1365_value);
			macroDef859->arr[i1] = closure845.lam(closure845.env, closure858.lam(closure858.env, i1).number_t_value).number_t_value;;
		}
		array_number_t y0 = macroDef859;
		card_t macroDef860 = x0->length;
		array_number_t macroDef929 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef929->length=macroDef860;
	macroDef929->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef860);
		for(int i1 = 0; i1 < macroDef929->length; i1++){
			env_t_1368 env_t_1368_value = make_empty_env(); closure_t closure863 = make_closure(lambda1368, &env_t_1368_value);
			env_t_1369 env_t_1369_value = make_env_t_1369(x0,w_cross_X,sintheta,costheta,cam); closure_t closure905 = make_closure(lambda1369, &env_t_1369_value);
			env_t_1378 env_t_1378_value = make_env_t_1378(tmp,theta_inv,cam); closure_t closure928 = make_closure(lambda1378, &env_t_1378_value);
			macroDef929->arr[i1] = closure863.lam(closure863.env, closure905.lam(closure905.env, i1).number_t_value, closure928.lam(closure928.env, i1).number_t_value).number_t_value;;
		}
		Xcam = macroDef929;;
	} else {
		env_t_1383 env_t_1383_value = make_env_t_1383(cam); closure_t closure933 = make_closure(lambda1383, &env_t_1383_value);
		env_t_1384 env_t_1384_value = make_env_t_1384(x0,cam); closure_t closure945 = make_closure(lambda1384, &env_t_1384_value);
		env_t_1387 env_t_1387_value = make_env_t_1387(cam); closure_t closure949 = make_closure(lambda1387, &env_t_1387_value);
		env_t_1388 env_t_1388_value = make_env_t_1388(x0,cam); closure_t closure961 = make_closure(lambda1388, &env_t_1388_value);
		env_t_1391 env_t_1391_value = make_env_t_1391(cam); closure_t closure965 = make_closure(lambda1391, &env_t_1391_value);
		env_t_1392 env_t_1392_value = make_env_t_1392(x0,cam); closure_t closure977 = make_closure(lambda1392, &env_t_1392_value);
		env_t_1395 env_t_1395_value = make_env_t_1395(cam); closure_t closure981 = make_closure(lambda1395, &env_t_1395_value);
		env_t_1396 env_t_1396_value = make_env_t_1396(x0,cam); closure_t closure993 = make_closure(lambda1396, &env_t_1396_value);
		env_t_1399 env_t_1399_value = make_env_t_1399(cam); closure_t closure997 = make_closure(lambda1399, &env_t_1399_value);
		env_t_1400 env_t_1400_value = make_env_t_1400(x0,cam); closure_t closure1009 = make_closure(lambda1400, &env_t_1400_value);
		env_t_1403 env_t_1403_value = make_env_t_1403(cam); closure_t closure1013 = make_closure(lambda1403, &env_t_1403_value);
		env_t_1404 env_t_1404_value = make_env_t_1404(x0,cam); closure_t closure1025 = make_closure(lambda1404, &env_t_1404_value);
		array_number_t y0 = (array_number_t)storage_alloc(sizeof(int) * 2);
	y0->length=3;
	y0->arr = (number_t*)storage_alloc(sizeof(number_t) * 3);
	y0->arr[0] = ((closure933.lam(closure933.env, 1).number_t_value) * (closure945.lam(closure945.env, 2).number_t_value)) - ((closure949.lam(closure949.env, 2).number_t_value) * (closure961.lam(closure961.env, 1).number_t_value));
	y0->arr[1] = ((closure965.lam(closure965.env, 2).number_t_value) * (closure977.lam(closure977.env, 0).number_t_value)) - ((closure981.lam(closure981.env, 0).number_t_value) * (closure993.lam(closure993.env, 2).number_t_value));
	y0->arr[2] = ((closure997.lam(closure997.env, 0).number_t_value) * (closure1009.lam(closure1009.env, 1).number_t_value)) - ((closure1013.lam(closure1013.env, 1).number_t_value) * (closure1025.lam(closure1025.env, 0).number_t_value));;
		card_t macroDef1026 = x0->length;
		array_number_t macroDef1042 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1042->length=macroDef1026;
	macroDef1042->arr = (number_t*)storage_alloc(sizeof(number_t) * macroDef1026);
		for(int i1 = 0; i1 < macroDef1042->length; i1++){
			env_t_1407 env_t_1407_value = make_empty_env(); closure_t closure1029 = make_closure(lambda1407, &env_t_1407_value);
			env_t_1408 env_t_1408_value = make_env_t_1408(x0,cam); closure_t closure1041 = make_closure(lambda1408, &env_t_1408_value);
			macroDef1042->arr[i1] = closure1029.lam(closure1029.env, closure1041.lam(closure1041.env, i1).number_t_value, y0->arr[i1]).number_t_value;;
		}
		Xcam = macroDef1042;;
	}
	array_number_t macroDef1043 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1043->length=(((9) + (1)) - (9)) + (1);
	macroDef1043->arr = (number_t*)storage_alloc(sizeof(number_t) * (((9) + (1)) - (9)) + (1));
		for(int i1 = 0; i1 < macroDef1043->length; i1++){
			
			macroDef1043->arr[i1] = cam->arr[(i1) + (9)];;
		}
	array_number_t rad_params = macroDef1043;
	array_number_t macroDef1044 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1044->length=((1) - (0)) + (1);
	macroDef1044->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1044->length; i1++){
			
			macroDef1044->arr[i1] = Xcam->arr[(i1) + (0)];;
		}
	array_number_t x2 = macroDef1044;
	number_t y0 = (1) / (Xcam->arr[2]);
	array_number_t macroDef1053 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1053->length=((1) - (0)) + (1);
	macroDef1053->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1053->length; i1++){
			env_t_1411 env_t_1411_value = make_env_t_1411(y0); closure_t closure1048 = make_closure(lambda1411, &env_t_1411_value);
			env_t_1412 env_t_1412_value = make_env_t_1412(Xcam); closure_t closure1052 = make_closure(lambda1412, &env_t_1412_value);
			macroDef1053->arr[i1] = closure1048.lam(closure1048.env, closure1052.lam(closure1052.env, i1).number_t_value).number_t_value;;
		}
	array_number_t proj = macroDef1053;
	array_number_t macroDef1070 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1070->length=((1) - (0)) + (1);
	macroDef1070->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1070->length; i1++){
			env_t_1413 env_t_1413_value = make_empty_env(); closure_t closure1056 = make_closure(lambda1413, &env_t_1413_value);
			env_t_1414 env_t_1414_value = make_env_t_1414(y0,Xcam); closure_t closure1069 = make_closure(lambda1414, &env_t_1414_value);
			macroDef1070->arr[i1] = closure1056.lam(closure1056.env, closure1069.lam(closure1069.env, i1).number_t_value).number_t_value;;
		}
	array_number_t v0 = macroDef1070;
	number_t macroDef1071 = 0;
	for(int cur_idx = 0; cur_idx < v0->length; cur_idx++){
		number_t cur = v0->arr[cur_idx];
		
		macroDef1071 = (macroDef1071) + (cur);;
	}
	number_t rsq = macroDef1071;
	env_t_1417 env_t_1417_value = make_env_t_1417(cam); closure_t closure1075 = make_closure(lambda1417, &env_t_1417_value);
	env_t_1418 env_t_1418_value = make_env_t_1418(cam); closure_t closure1079 = make_closure(lambda1418, &env_t_1418_value);
	number_t L = ((1) + ((closure1075.lam(closure1075.env, 0).number_t_value) * (rsq))) + (((closure1079.lam(closure1079.env, 1).number_t_value) * (rsq)) * (rsq));
	array_number_t macroDef1097 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1097->length=((1) - (0)) + (1);
	macroDef1097->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1097->length; i1++){
			env_t_1419 env_t_1419_value = make_env_t_1419(L); closure_t closure1083 = make_closure(lambda1419, &env_t_1419_value);
			env_t_1420 env_t_1420_value = make_env_t_1420(y0,Xcam); closure_t closure1096 = make_closure(lambda1420, &env_t_1420_value);
			macroDef1097->arr[i1] = closure1083.lam(closure1083.env, closure1096.lam(closure1096.env, i1).number_t_value).number_t_value;;
		}
	array_number_t distorted = macroDef1097;
	array_number_t macroDef1098 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1098->length=(((7) + (1)) - (7)) + (1);
	macroDef1098->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1098->length; i1++){
			
			macroDef1098->arr[i1] = cam->arr[(i1) + (7)];;
		}
	array_number_t x3 = macroDef1098;
	number_t y1 = cam->arr[6];
	array_number_t macroDef1126 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1126->length=((1) - (0)) + (1);
	macroDef1126->arr = (number_t*)storage_alloc(sizeof(number_t) * ((1) - (0)) + (1));
		for(int i1 = 0; i1 < macroDef1126->length; i1++){
			env_t_1423 env_t_1423_value = make_env_t_1423(y1); closure_t closure1102 = make_closure(lambda1423, &env_t_1423_value);
			env_t_1424 env_t_1424_value = make_env_t_1424(y0,Xcam,L); closure_t closure1125 = make_closure(lambda1424, &env_t_1424_value);
			macroDef1126->arr[i1] = closure1102.lam(closure1102.env, closure1125.lam(closure1125.env, i1).number_t_value).number_t_value;;
		}
	array_number_t y2 = macroDef1126;
	array_number_t macroDef1168 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1168->length=(((7) + (1)) - (7)) + (1);
	macroDef1168->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1168->length; i1++){
			env_t_1429 env_t_1429_value = make_empty_env(); closure_t closure1129 = make_closure(lambda1429, &env_t_1429_value);
			env_t_1430 env_t_1430_value = make_env_t_1430(cam); closure_t closure1133 = make_closure(lambda1430, &env_t_1430_value);
			env_t_1431 env_t_1431_value = make_env_t_1431(y1,y0,Xcam,L); closure_t closure1167 = make_closure(lambda1431, &env_t_1431_value);
			macroDef1168->arr[i1] = closure1129.lam(closure1129.env, closure1133.lam(closure1133.env, i1).number_t_value, closure1167.lam(closure1167.env, i1).number_t_value).number_t_value;;
		}
	array_number_t x4 = macroDef1168;
	array_number_t macroDef1221 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1221->length=(((7) + (1)) - (7)) + (1);
	macroDef1221->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1221->length; i1++){
			env_t_1438 env_t_1438_value = make_empty_env(); closure_t closure1171 = make_closure(lambda1438, &env_t_1438_value);
			env_t_1439 env_t_1439_value = make_env_t_1439(y1,y0,cam,Xcam,L); closure_t closure1220 = make_closure(lambda1439, &env_t_1439_value);
			macroDef1221->arr[i1] = closure1171.lam(closure1171.env, closure1220.lam(closure1220.env, i1).number_t_value, feat0->arr[i1]).number_t_value;;
		}
	array_number_t x5 = macroDef1221;
	array_number_t macroDef1287 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1287->length=(((7) + (1)) - (7)) + (1);
	macroDef1287->arr = (number_t*)storage_alloc(sizeof(number_t) * (((7) + (1)) - (7)) + (1));
		for(int i1 = 0; i1 < macroDef1287->length; i1++){
			env_t_1449 env_t_1449_value = make_env_t_1449(w0); closure_t closure1225 = make_closure(lambda1449, &env_t_1449_value);
			env_t_1450 env_t_1450_value = make_env_t_1450(y1,y0,feat0,cam,Xcam,L); closure_t closure1286 = make_closure(lambda1450, &env_t_1450_value);
			macroDef1287->arr[i1] = closure1225.lam(closure1225.env, closure1286.lam(closure1286.env, i1).number_t_value).number_t_value;;
		}
	value_t res;
	res.array_number_t_value = macroDef1287;
	return res;
}
typedef struct env_t_1462 {
	card_t s;
} env_t_1462;
env_t_1462 make_env_t_1462(card_t s) {
	env_t_1462 env;
	env.s = s;
	return env;
}

value_t lambda1462(env_t_1462* env1297, index_t i0) {
	card_t s1296 = env1297->s;
	value_t res;
	res.number_t_value = (double)(((s1296)) + (i0));
	return res;
}
array_array_number_t TOP_LEVEL_usecases_ba_reproj_err_3(array_array_number_t cams, array_array_number_t x, array_number_t w, array_array_number_t obs, array_array_number_t feat) {
	card_t macroDef570 = cams->length;
	card_t n = macroDef570;
	card_t macroDef571 = w->length;
	card_t p = macroDef571;
	card_t s = 0;
	card_t e = (p) - (1);
	array_number_t macroDef572 = (array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef572->length=((e) - (s)) + (1);
	macroDef572->arr = (number_t*)storage_alloc(sizeof(number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef572->length; i++){
			
			macroDef572->arr[i] = (double)(((s)) + (i));;
		}
	array_number_t range = macroDef572;
	array_array_number_t macroDef1300 = (array_array_number_t)storage_alloc(sizeof(int) * 2);
	macroDef1300->length=((e) - (s)) + (1);
	macroDef1300->arr = (array_number_t*)storage_alloc(sizeof(array_number_t) * ((e) - (s)) + (1));
		for(int i = 0; i < macroDef1300->length; i++){
			env_t_1301 env_t_1301_value = make_env_t_1301(x,w,obs,feat,cams); closure_t closure1295 = make_closure(lambda1301, &env_t_1301_value);
			env_t_1462 env_t_1462_value = make_env_t_1462(s); closure_t closure1299 = make_closure(lambda1462, &env_t_1462_value);
			macroDef1300->arr[i] = closure1295.lam(closure1295.env, closure1299.lam(closure1299.env, i).number_t_value).array_number_t_value;;
		}
	return macroDef1300;
}
#endif
