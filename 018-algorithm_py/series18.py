def series18(N):
    """Implement your function below"""
    sequence = []
    
    for i in range(3 * N):
        value = -(N * N) + (i * i)
        sequence.append(value)
        
    print(" ".join(map(str, sequence)))