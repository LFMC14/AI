# Missionaries and Cannibals

The purpose of this program is to find a solution to the missionaries and cannibals problem. The goal is to move all missionaries and cannibals to opposite side of the river from which they started. The rules are:

1. All missionaries and cannibals start on the same side of the river
2. Cannibals cannot outnumber the missionaries on either side
2. The boat can carry up to two people
3. The boat cannot travel by itself (one person minimum)

My algorithm solves this problem by using a structure named, ```State```, which represents the current state (how many cannibals and missionaries on both sides of the river and which side boat the is on), keeps track of the previous state, and a vector which has all valid "future" states.
