perf record -F 99 -g -o flame.perf -- ./flame
perf script -i flame.perf > out.perf
