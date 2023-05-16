crappy jupyter

project to learn emscripten dynamic linking

UI:

- a <input> for a number
- a <select> to select a 'kernel'
- <button> run

- kernels:
  - add 5
  - mul 10

Architecture:
- 100% emscripten engine, let's do 
- JS interface to call Poopyter.compile('...')
- thin JS to glue UI to engine
- some interface in the engine for compile,
  compile + run
- kernels ship as wasm .so's
- engine dlopens kernels

------------

* run `./build_emscripten.sh`
* run `caddy start`
* visit https://poopyter.localhost/


