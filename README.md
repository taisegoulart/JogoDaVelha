# Jogo da Velha em linguagem C

Esse projeto é uma tentativa de recriar o jogo-da-velha, um jogo muito popular que surgiu em meados do século XIX, no Reino Unido. Nessa época, era comum as senhoras se reunirem para jogar "*noughts and crosses*"-zeros e cruzes, em uma tradução livre - enquanto bordavam e conversavam. 

### Regras:
- O jogo ocorre em um tabuleiro 3x3;
- O jogo será para duas pessoas jogarem, alternadamente;
- O jogo sempre começa com o jogador 1, que é o X;
- O jogador 2 sempre será a O e jogará logo após o jogador 1;
- O jogo dura de 5 até 9 turnos (referente as posições disponíveis para serem preenchidas no tabuleiroe a alternância das jogadas entre os participantes) e  pode ter 3 resultados: vitória do jogador 1, vitória do jogador 2 ou empate, e esta informação é dada no final do jogo;
- Ganha o jogador que primeiro formar uma reta na diagonal, vertical ou horizontal do tabuleiro.

O sistema é uma CLI  e o jogo deverá ser executado numa IDE compatível com a linguagem C. Pode-se também executar este projeto por meio do código no repositório da plataforma replit, neste [link](https://replit.com/@taisegoulart/JogoDaVelhaMelhorado#main.c "link")

### Prevenções de erro previstas pelo programa:
- O jogo não permite que o jogador insira uma posição diferente das válidas (de 1 a 9), nem mesmo caracteres errôneos (por exemplo, digitar uma letra ao invés de um número);
- O jogo não permite que um jogador preencha uma posição já ocupada;
- O jogo termina quando há um vencedor, mesmo que o tabuleiro não esteja totalmente preenchido.

### Melhorias futuras
- Implementar algumas funções para melhor recursividade (por exemplo, uma função para imprimir o tabuleiro);
- Permitir que o usuário reinicie o jogo se quiser.
