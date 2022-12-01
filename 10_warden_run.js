const cp = require("child_process");
let sim = cp.spawn("python",["10_warden_sim.py"]);
let prog = cp.spawn("a.out");
sim.stdout.pipe(prog.stdin);
prog.stdout.pipe(sim.stdin);
sim.stdout.pipe(process.stdout);
prog.stdout.pipe(process.stdout);