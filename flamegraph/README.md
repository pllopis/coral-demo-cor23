## Flame Graph Demo

This just contains sample code (flame.c) and scripts to generate a flame graph of this code (.sh files).

First, you will need [FlameGraph](https://github.com/brendangregg/FlameGraph) and Linux's perf tool.

Note that to gather the stack traces with perf, you may need sufficient privileges (either root, or sysctl parameter `kernel.perf_event_paranoid` set to `1` or lower).

### Build scripts

`build.sh` builds flame.c into flame.
`capture.sh` runs flame and captures call stacks (measurement step).
`fold.sh` transforms perf output into a flamegraph-friendly file format (that allows for filtering of certain stacks with grep). Perl required.
`graph.sh` produces the flamegraph in .svg format. Perl required.

Before running the scripts, set the path to the FlameGraph repo:
```
export FLAMEGRAPH_DIR=/home/llopis/src/FlameGraph
```
