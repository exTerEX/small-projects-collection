quick.sort <- function(vector) {
  if (length(vector) <= 1) {
    return(vector)
  }

  pivot <- vector[1]
  non.pivot  <- vector[-1]
  pivot_less    <- quick.sort(non.pivot[non.pivot < pivot])
  pivot_greater <- quick.sort(non.pivot[non.pivot >= pivot])

  return (c(pivot_less, pivot, pivot_greater))
}

insertion.sort(c(9, 5, 0, 7, 2, 3, 6, 1, 4, 8))
