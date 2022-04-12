# Compactador de endereço IPv6

Na internet os computadores, roteadores e demais dispositivos são endereçados com um número que os identifica globalmente, denominado endereço IP. A versão atual do protocolo que especifica esse tipo de endereço se chama IPv6, e define que os endereços devem ter 128 bits ([verbete na Wikipedia](https://pt.wikipedia.org/wiki/IPv6)).

Endereços IPv6 são expressados com uma notação hexadecimal, sendo divididos em segmentos de 16 bits delimitados por : (dois pontos). Essa notação tem a finalidade de descrever endereços IPv6 para os usuários. Estes são alguns exemplos de endereços IPv6:

```
fe80::cad3:a3ff:fe9f:d173
2800:3f0:4001:816::2004
2804:1454:1004:102::3
```

Um detalhe existe quanto a essa forma de escrever endereços IPv6. Se um endereço é apresentado com segmentos de 16 bits intercalados por :, então deve apresentar 8 sequências de dígitos hexadecimais separadas por :. No entanto, nos exemplos os endereços possuem sequências menores de dígitos hexadecimais. Isso se deve a uma forma compacta de mostrar um endereço. Segmentos de 16 bits sucessivos formados por bits 0 podem ser omitidos, sendo representados por ::. Sendo assim, os endereços mostrados no exemplo, se escritos por completo, ficam assim:

```
fe80:0:0:0:cad3:a3ff:fe9f:d173
2800:3f0:4001:816:0:0:0:2004
2804:1454:1004:102:0:0:0:
```

Num caso extremo, o endereço ::1 (que é válido), corresponde na verdade a 0:0:0:0:0:0:0:1.

Escreva uma função que contraia um endereço IPv6. Essa função recebe como parâmetro um endereço em sua forma expandida, e devolve como resultado o endereço em forma compacta:

```c++
string compacta_ipv6(const string & ip6);
```

O uso de lista, combinada com a [função separa](https://github.com/IFSC-Engtelecom-Prg2/Lista_Separa), deve ajudar na solução.