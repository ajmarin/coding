import pandas as pd

def findHeavyAnimals(df: pd.DataFrame) -> pd.DataFrame:
    return df[df["weight"] > 100].sort_values("weight", ascending=False)[["name"]]

