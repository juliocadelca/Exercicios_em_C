#include <iostream>
#include <vector>
#include <string>

class Livro {
public:
    std::string titulo;
    std::string autor;

    Livro(const std::string& t, const std::string& a) : titulo(t), autor(a) {}
};

class Biblioteca {
private:
    std::vector<Livro> livros;

public:
    void adicionarLivro(const std::string& titulo, const std::string& autor) {
        // Usando push_back em vez de emplace_back
        livros.push_back(Livro(titulo, autor));
        std::cout << "Livro adicionado: " << titulo << " de " << autor << std::endl;
    }

    void removerLivro(const std::string& titulo) {
        // Usando iteradores padrão sem auto
        std::vector<Livro>::iterator it;
        for (it = livros.begin(); it != livros.end(); ++it) {
            if (it->titulo == titulo) {
                livros.erase(it);
                std::cout << "Livro removido: " << titulo << std::endl;
                return;
            }
        }
        std::cout << "Livro não encontrado: " << titulo << std::endl;
    }

    void exibirLivros() const {
        if (livros.empty()) {
            std::cout << "Nenhum livro na biblioteca." << std::endl;
            return;
        }
        std::cout << "Livros na biblioteca:" << std::endl;
        for (std::vector<Livro>::const_iterator it = livros.begin(); it != livros.end(); ++it) {
            std::cout << "- " << it->titulo << " de " << it->autor << std::endl;
        }
    }
};

int main() {
    Biblioteca minhaBiblioteca;
    minhaBiblioteca.adicionarLivro("1984", "George Orwell");
    minhaBiblioteca.adicionarLivro("O Senhor dos Anéis", "J.R.R. Tolkien");
    
    minhaBiblioteca.exibirLivros();
    
    minhaBiblioteca.removerLivro("1984");
    minhaBiblioteca.exibirLivros();
    
    minhaBiblioteca.removerLivro("O Hobbit"); // Tentativa de remover um livro que não existe

    return 0;
}