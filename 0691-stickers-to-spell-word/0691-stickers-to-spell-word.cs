public class Solution
{
    Dictionary<string, int> _memo = [];

    public int MinStickers(string[] stickers, string target)
    {
        int[][] stickerCount = new int[stickers.Length][];
        for (int i = 0; i < stickers.Length; i++)
        {
            stickerCount[i] = new int[26];
            foreach (char c in stickers[i])
                stickerCount[i][c - 'a']++;
        }

        int ans = Dfs(stickerCount, target);
        return ans;
    }

    private int Dfs(int[][] stickers, string target)
    {
        if (target.Length == 0)
            return 0;

        if (_memo.ContainsKey(target))
            return _memo[target];

        int[] targetCount = new int[26];
        foreach (char c in target)
            targetCount[c - 'a']++;

        int res = int.MaxValue;

        foreach (var sticker in stickers)
        {
            if (sticker[target[0] - 'a'] == 0)
                continue;

            StringBuilder sb = new();
            for (int i = 0; i < 26; i++)
            {
                int remain = targetCount[i] - sticker[i];
                for (int k = 0; k < int.Max(0, remain); k++)
                    sb.Append((char)(i + 'a'));
            }

            string newTarget = sb.ToString();
            int temp = Dfs(stickers, newTarget);
            if (temp != -1)
                res = int.Min(res, 1 + temp);
        }

        _memo[target] = (res == int.MaxValue) ? -1 : res;
        return _memo[target];
    }
}