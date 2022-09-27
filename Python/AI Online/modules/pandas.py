import pandas as pd
df = pd.read_csv("pokemon_data.csv")
#df1 = pd.read_excel("pokemon_data.xlsx")
#df2 = pd.read_csv("pokemon_data.txt", delimiter='\t')
#print(df[['Name', 'Type 1', 'Type 2']])
'''
print(df.columns)
print(df.sort_values(['Type 1', 'Attack'], ascending=[1,0]))
'''
print(df.loc[(df['Type 1']=='Grass') | (df['Type 2']=='Dragon')])