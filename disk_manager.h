Disco* disco_cria(char* nome, unsigned long tamanho);
bool disco_grava(Disco* d, char* arquivo); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_remove(Disco* d, char* nome); // somente o nome do arquivo sem o caminho
bool disco_recupera(Disco* d, char* nome, char* arquivoDestino); // nome arquivo deve conter o caminho absoluto ou relativo do arquivo
bool disco_lista(Disco* d, char* saida);