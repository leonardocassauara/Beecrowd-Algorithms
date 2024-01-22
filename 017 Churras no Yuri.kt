import java.util.*

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/2633

fun merge(dados: MutableList<List<String>>, inicio: Int, meio: Int, fim: Int) {

    var j: Int
    var tamanhoLeft: Int = meio - inicio
    var tamanhoRight: Int = fim - meio
    var topoLeft: Int = 0
    var topoRight: Int = 0
    var left: MutableList<List<String>> = MutableList(tamanhoLeft) { mutableListOf<String>() }
    var right: MutableList<List<String>> = MutableList(tamanhoRight) { mutableListOf<String>() }

    j = 0
    for (i in inicio until meio) {

        left[j] = dados[i]
        j = j + 1
    }

    j = 0
    for (i in meio until fim) {

        right[j] = dados[i]
        j = j + 1
    }

    for (k in inicio until fim) {

        if (topoLeft >= tamanhoLeft) {

            dados[k] = right[topoRight]
            topoRight = topoRight + 1
        }
        else if (topoRight >= tamanhoRight) {

            dados[k] = left[topoLeft]
            topoLeft = topoLeft + 1
        }
        else if (left[topoLeft][1].toInt() < right[topoRight][1].toInt()) {

            dados[k] = left[topoLeft]
            topoLeft = topoLeft + 1
        }
        else {

            dados[k] = right[topoRight]
            topoRight = topoRight + 1
        }
    }
}


fun mergeSort(dados: MutableList<List<String>>, inicio: Int, fim: Int) : Unit {

    var meio: Int;

    if ((fim - inicio) > 1) {

        meio = (fim + inicio) / 2
        mergeSort(dados, inicio, meio)
        mergeSort(dados, meio, fim)
        merge(dados, inicio, meio, fim)
    }
}


fun main(args: Array<String>) {

    while(true) {

        val numInput = readLine()?.toInt()
        
        if (numInput == null) {
            
            break
        }
        
        var listaCarnesEdia = mutableListOf<List<String>>()

        for (i in 0 until numInput) {

            var carnesEdia = readLine()!!
            listaCarnesEdia.add(carnesEdia.split(" "))
        }
            
        mergeSort(listaCarnesEdia, 0, numInput)

        for (i in 0 until numInput) {

            if (i != numInput - 1) {

                print("${listaCarnesEdia[i][0]} ")
            }
            else {

                print("${listaCarnesEdia[i][0]}\n")
            }
        }
    }

}