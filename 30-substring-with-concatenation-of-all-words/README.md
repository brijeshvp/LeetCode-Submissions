<h2><a href="https://leetcode.com/problems/substring-with-concatenation-of-all-words/">30. Substring with Concatenation of All Words</a></h2><h3>Hard</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given a string <code style="user-select: auto;">s</code> and an array of strings <code style="user-select: auto;">words</code> of <strong style="user-select: auto;">the same length</strong>. Return&nbsp;all starting indices of substring(s) in <code style="user-select: auto;">s</code>&nbsp;that is a concatenation of each word in <code style="user-select: auto;">words</code> <strong style="user-select: auto;">exactly once</strong>, <strong style="user-select: auto;">in any order</strong>,&nbsp;and <strong style="user-select: auto;">without any intervening characters</strong>.</p>

<p style="user-select: auto;">You can return the answer in <strong style="user-select: auto;">any order</strong>.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "barfoothefoobarman", words = ["foo","bar"]
<strong style="user-select: auto;">Output:</strong> [0,9]
<strong style="user-select: auto;">Explanation:</strong> Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
<strong style="user-select: auto;">Output:</strong> []
</pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
<strong style="user-select: auto;">Output:</strong> [6,9,12]
</pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= s.length &lt;= 10<sup style="user-select: auto;">4</sup></code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">s</code> consists of lower-case English letters.</li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= words.length &lt;= 5000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= words[i].length &lt;= 30</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">words[i]</code>&nbsp;consists of lower-case English letters.</li>
</ul>
</div>