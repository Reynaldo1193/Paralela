import time
import websites
import Utilities


start_time = time.time()

for address in websites.WEBSITE_LIST:
    Utilities.check_website(address)

end_time = time.time()

print("Time taken Serialiced: %ssecs" % (end_time - start_time))
