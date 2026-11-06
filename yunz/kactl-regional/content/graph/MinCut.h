/**
 * Uses: recover the min cut set (which vertices are on source side), project selection / closure problems, which edges to delete to disconnect s and t.
 * Author: Simon Lindholm
 * Date: 2015-05-13
 * Source: Wikipedia
 * Description: After running max-flow, the left side of a min-cut from $s$ to $t$ is given
 * by all vertices reachable from $s$, only traversing edges with positive residual capacity.
 * Status: works
 */
