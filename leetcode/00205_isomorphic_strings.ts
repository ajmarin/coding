function isIsomorphic(s: string, t: string): boolean {
    const mapping: Record<string, string> = {};
    const mapped = new Set();
    for (let i = 0; i < s.length; ++i) {
        const sc = s[i], tc = t[i];
        if (!(sc in mapping) && !mapped.has(tc)) {
            mapping[sc] = tc;
            mapped.add(tc);
        }
        if (mapping[sc] !== tc) return false;
    }
    return true;
};

