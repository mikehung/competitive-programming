class Solution:
    def similarRGB(self, color):
        """
        :type color: str
        :rtype: str
        """
        def min_short_color(color):
            min_short_color, min_diff = None, float('inf')
            for short_color in short_colors:
                diff = abs(int(short_color, 16)-int(color, 16))
                if diff < min_diff:
                    min_diff = diff
                    min_short_color = short_color
            return min_short_color

        short_colors = [h*2 for h in '0123456789abcdef']
        ans = ['#']
        for i in range(3):
            ans.append(min_short_color('{}{}'.format(color[2*i+1], color[2*i+2])))
        return ''.join(ans)

print(Solution().similarRGB("#09f166"))
