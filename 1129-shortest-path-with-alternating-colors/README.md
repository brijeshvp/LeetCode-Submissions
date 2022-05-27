<h2><a href="https://leetcode.com/problems/shortest-path-with-alternating-colors/">1129. Shortest Path with Alternating Colors</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given an integer <code style="user-select: auto;">n</code>, the number of nodes in a directed graph where the nodes are labeled from <code style="user-select: auto;">0</code> to <code style="user-select: auto;">n - 1</code>. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.</p>

<p style="user-select: auto;">You are given two arrays <code style="user-select: auto;">redEdges</code> and <code style="user-select: auto;">blueEdges</code> where:</p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">redEdges[i] = [a<sub style="user-select: auto;">i</sub>, b<sub style="user-select: auto;">i</sub>]</code> indicates that there is a directed red edge from node <code style="user-select: auto;">a<sub style="user-select: auto;">i</sub></code> to node <code style="user-select: auto;">b<sub style="user-select: auto;">i</sub></code> in the graph, and</li>
	<li style="user-select: auto;"><code style="user-select: auto;">blueEdges[j] = [u<sub style="user-select: auto;">j</sub>, v<sub style="user-select: auto;">j</sub>]</code> indicates that there is a directed blue edge from node <code style="user-select: auto;">u<sub style="user-select: auto;">j</sub></code> to node <code style="user-select: auto;">v<sub style="user-select: auto;">j</sub></code> in the graph.</li>
</ul>

<p style="user-select: auto;">Return an array <code style="user-select: auto;">answer</code> of length <code style="user-select: auto;">n</code>, where each <code style="user-select: auto;">answer[x]</code> is the length of the shortest path from node <code style="user-select: auto;">0</code> to node <code style="user-select: auto;">x</code> such that the edge colors alternate along the path, or <code style="user-select: auto;">-1</code> if such a path does not exist.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
<strong style="user-select: auto;">Output:</strong> [0,1,-1]
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
<strong style="user-select: auto;">Output:</strong> [0,1,-1]
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= n &lt;= 100</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= redEdges.length,&nbsp;blueEdges.length &lt;= 400</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">redEdges[i].length == blueEdges[j].length == 2</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">0 &lt;= a<sub style="user-select: auto;">i</sub>, b<sub style="user-select: auto;">i</sub>, u<sub style="user-select: auto;">j</sub>, v<sub style="user-select: auto;">j</sub> &lt; n</code></li>
</ul>
</div>