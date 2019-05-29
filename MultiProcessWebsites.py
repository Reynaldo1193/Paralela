
import time
import websites
import Utilities
import multiprocessing

NUM_WORKERS = 4

start_time = time.time()

with multiprocessing.Pool(processes=NUM_WORKERS) as pool:
    results = pool.map_async(Utilities.check_website, websites.WEBSITE_LIST)
    results.wait()

end_time = time.time()

print("Time for MultiProcessingSquirrel: %ssecs" % (end_time - start_time))
