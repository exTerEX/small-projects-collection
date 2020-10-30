bubble.sort <- function(vector) {
  for (index in 1:(length(vector) - 1)) {
    for (jndex in 1:(length(vector) - index)) {
      if (vector[jndex + 1] < vector[jndex]) {
        temp <- vector[jndex]
        vector[jndex] <- vector[jndex + 1]
        vector[jndex + 1] <- temp
      }
    }
  }
  return(vector)
}

insertion.sort(c(9, 5, 0, 7, 2, 3, 6, 1, 4, 8))