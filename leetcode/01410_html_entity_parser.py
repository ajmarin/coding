class Solution:
    replacements = [
        ("&quot", "\""),
        ("&apos", "'"),
        ("&gt", ">"),
        ("&lt", "<"),
        ("&frasl", "/"),
        ("&amp", "&"),
    ]

    def entityParser(self, text: str) -> str:
        for find, replace in self.replacements:
            text = text.replace(find + ";", replace)
        return text