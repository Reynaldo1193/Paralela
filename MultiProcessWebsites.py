
import time
import websites
import Utilities
import multiprocessing

NUM_WORKERS = multiprocessing.cpu_count()

start_time = time.time()

with multiprocessing.Pool(processes=NUM_WORKERS) as pool:
    results = pool.map_async(Utilities.check_website, websites.WEBSITE_LIST)
    results.wait()

end_time = time.time()

print("Time taken with Multiple Processors: %ssecs" % (end_time - start_time))
