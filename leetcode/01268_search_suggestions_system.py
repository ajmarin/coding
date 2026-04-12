class Solution:
    def suggestedProducts(
        self, products: List[str], searchWord: str
    ) -> List[List[str]]:
        suggestions = deque([])
        available_products = deque(sorted(products))
        prefix = ""
        ans = []
        for i, c in enumerate(searchWord):
            prefix += c
            for tr in [s for s in suggestions if len(s) <= i or s[i] != c]:
                suggestions.remove(tr)
            while available_products and len(suggestions) < 3:
                product = available_products.popleft()
                if product.startswith(prefix):
                    suggestions.append(product)
            ans.append(list(suggestions))
        return ans
