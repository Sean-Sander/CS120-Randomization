# M2OEP-Randomization-vlai-dmelkumo-ssander-amtownse

# Report
To determine which randomization algorithm did the best,
we decided to look at the number of times the vectors ended up 
repeating themselves over a set amount of trials.
We also measured the amount of time each algorithm took to run through 
the testing function.

Method test results: https://imgur.com/a/ItpTYdN

As can be seen from the test results, most of the randomization algorithms
performed quite similarly to one another with the average number of repeats
being 10 and under. Vincent's algorithm was the outlier with occurrences much
higher than the others with an average of 80,000. Alex had the best algorithm
using this metric with an average of 3.2 occurrences.
Looking at the speed of the algorithms showed times ranging from the 3 seconds
of Vincent's algorithm to 21 seconds for Sean's. Alex's was on the lower end at 7
seconds and David on the higher end at 18 seconds. Overall, when considering
both the number of occurrences and the amount of time taken, Alex's algorithm clearly
worked the best.
