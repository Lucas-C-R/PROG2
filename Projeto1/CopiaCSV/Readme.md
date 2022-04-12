# Busca de dados em arquivo .csv

Um arquivo [CSV](https://pt.wikipedia.org/wiki/Comma-separated_values) é formado por linhas contendo valores separados por vírgulas. Ele pode ser usado para representar uma tabela, e nesse caso a primeira linha pode conter os nomes das colunas. Veja este exemplo de arquivo CSV:

```
ano,marca,modelo,info,preco
1997,Ford,E350,"ac, abs, moon",30100.00
1999,Chevy,"Venture ",,49000.00
1996,Jeep,Grand Cherokee,"MUST SELL! air, moon roof, loaded",479699.00
```

Ele representa esta tabela:

ano|marca|modelo|info|preco
---|---|---|---|---
1997|Ford|E350|"ac, abs, moon"|30100.00
1999|Chevy|"Venture| "Extended Edition"|49000.00
1996|Jeep|Grand Cherokee|"MUST SELL! air, moon roof, loaded"|479699.00

Escreva um programa que procura todas as linhas de um arquivo CSV que possuam um determinado valor em uma coluna específica. O nome do arquivo CSV, e o nome da coluna, são informados por argumentos de linha de comando. Cada linha do arquivo que satisfizer o critério de busca deve ser mostrada na tela.

Tente aplicar seu programa às estatísticas sobre Covid disponibilizadas [nesta base de dados pública](https://brasil.io/dataset/covid19/caso/) ! O arquivo [casos-sc.csv](./casos-sc.csv) contém dados sobre os municípios de SC.
