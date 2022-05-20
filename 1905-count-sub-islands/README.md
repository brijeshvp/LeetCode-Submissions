<h2><a href="https://leetcode.com/problems/count-sub-islands/">1905. Count Sub Islands</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given two <code style="user-select: auto;">m x n</code> binary matrices <code style="user-select: auto;">grid1</code> and <code style="user-select: auto;">grid2</code> containing only <code style="user-select: auto;">0</code>'s (representing water) and <code style="user-select: auto;">1</code>'s (representing land). An <strong style="user-select: auto;">island</strong> is a group of <code style="user-select: auto;">1</code>'s connected <strong style="user-select: auto;">4-directionally</strong> (horizontal or vertical). Any cells outside of the grid are considered water cells.</p>

<p style="user-select: auto;">An island in <code style="user-select: auto;">grid2</code> is considered a <strong style="user-select: auto;">sub-island </strong>if there is an island in <code style="user-select: auto;">grid1</code> that contains <strong style="user-select: auto;">all</strong> the cells that make up <strong style="user-select: auto;">this</strong> island in <code style="user-select: auto;">grid2</code>.</p>

<p style="user-select: auto;">Return the <em style="user-select: auto;"><strong style="user-select: auto;">number</strong> of islands in </em><code style="user-select: auto;">grid2</code> <em style="user-select: auto;">that are considered <strong style="user-select: auto;">sub-islands</strong></em>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/10/test1.png" style="width: 493px; height: 205px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
<strong style="user-select: auto;">Output:</strong> 3
<strong style="user-select: auto;">Explanation: </strong>In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png" style="width: 491px; height: 201px; user-select: auto;">
<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
<strong style="user-select: auto;">Output:</strong> 2 
<strong style="user-select: auto;">Explanation: </strong>In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">m == grid1.length == grid2.length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">n == grid1[i].length == grid2[i].length</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= m, n &lt;= 500</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">grid1[i][j]</code> and <code style="user-select: auto;">grid2[i][j]</code> are either <code style="user-select: auto;">0</code> or <code style="user-select: auto;">1</code>.</li>
</ul>
</div>