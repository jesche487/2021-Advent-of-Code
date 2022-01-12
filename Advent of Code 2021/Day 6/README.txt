Day 2 used a smarter way of solving this
Instead of having a whole array of the lanternfish, we kept track of how many of each day of fish there were,
and operated on a counts vector instead. By shifting and adding counts[0] to 6 and 8, we did the same thing
but with way less space.

Aso I had to use long long instead of int due to overflow.