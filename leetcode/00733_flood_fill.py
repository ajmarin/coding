class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, newColor: int) -> List[List[int]]:
        rows = len(image)
        cols = len(image[0]) if rows else 0
        def valid(i: int, j: int) -> bool:
            return 0 <= i < rows and 0 <= j < cols
        directions = [[1,0],[0,1],[-1,0],[0,-1]]
        old = image[sr][sc]
        seen = set()
        q = collections.deque()
        q.append((sr, sc))
        seen.add((sr, sc))
        while q:
            i, j = q.pop()
            for ii, jj in directions:
                key = i + ii, j + jj
                if key not in seen and valid(*key) and image[key[0]][key[1]] == old:
                    q.append(key)
                    seen.add(key)
            image[i][j] = newColor
        return image