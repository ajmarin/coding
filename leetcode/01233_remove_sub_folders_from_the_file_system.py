class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort()
        all_folders = set()
        for f in folder:
            parts = [x for x in f.split('/') if x]
            is_subfolder = False
            path = ''
            for i in range(len(parts) - 1):
                path = path + '/' + parts[i]
                if path in all_folders:
                    is_subfolder = True
                    break
            if not is_subfolder:
                all_folders.add(f)
        return list(all_folders)