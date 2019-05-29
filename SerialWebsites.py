# serial_squirrel.py

import time
import websites
import Utilities


start_time = time.time()

for address in websites.WEBSITE_LIST:
    Utilities.check_website(address)

end_time = time.time()

print("Time for SerialSquirrel: %ssecs" % (end_time - start_time))
