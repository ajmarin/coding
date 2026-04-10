import pandas as pd


def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    quarters = [f"quarter_{i+1}" for i in range(4)]
    return report.melt(
        id_vars="product", value_vars=quarters, var_name="quarter", value_name="sales"
    )
