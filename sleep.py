import time

loop = int(input("loop:"))
wait = float(input("wait:"))

print("wait time = %d\n"
      "loop times = %d" % (wait, loop))

total = 0

for i in range(loop):
    start = time.perf_counter()
    time.sleep(wait)
    end = time.perf_counter()
    wait_time = (end - start)
    print("waited time = %f" % wait_time)
    total += wait_time

awt = (total / loop)
print("Average waited time (AWT) = %f" % awt)
print("difference between input and AWT = %f" % (awt / wait))
