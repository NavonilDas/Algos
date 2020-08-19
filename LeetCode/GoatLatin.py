class Solution:
    def toGoatLatin(self, S: str) -> str:
        vowl = "aeiouAEIOU"
        words = S.split()
        ongoing = "a"
        ans = []
        for word in words:
            if word[0] in vowl:
                ans.append(word + "ma" + ongoing)
            else:
                x = word[0]
                ans.append(word[1:] + x + "ma"+ongoing)
            ongoing += "a"
        # print(words)
        return " ".join(ans)