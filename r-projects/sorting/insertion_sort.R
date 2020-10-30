insertion.sort <- function(vector) {
  for (index in 2:length(vector)) {
    key = vector[index]
    jndex = index - 1

    while (jndex > 0 && vector[jndex] > key) {
      vector[jndex + 1] = vector[jndex]
      jndex = jndex - 1
    }
    vector[jndex + 1] = key
  }
  return(vector)
}

insertion.sort(c(9, 5, 0, 7, 2, 3, 6, 1, 4, 8))