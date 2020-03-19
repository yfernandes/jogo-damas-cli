#pragma once
#include "common.h"

int isValidMove(Tile Board[], int start, int end)
{
    int code = -6, // Number that is returnd in order to carry the game
        startRow = start / 4, startColumn = start % 4, endRow = end / 4,
        endColumn = end % 4;

    // Codes :
    //-6 = Nao implementado
    //-1 = Movimento invalido
    // 0 = Pedra inicial não existe;
    // 1 = Pedra pode Mover
    // 2 = Pedra pode Comer NAO IMPLEMENTADO
    // 3 = Dama pode Comer  NAO IMPLEMENTADO
    // 4 = Pedra Pode Comer Multiplas vezes NAO IMPLEMENTADO
    // 5 = Dama Pode Comer Multiplas vezes NAO IMPLEMENTADO
    // 6 = Tornar Dama NAO IMPLEMENTADO

    // Checar se o movimento é diagonal. Linha + ou - 1, coluna

    if (Board[start].isOccupied == true) { // Checar se pode mover peça
        if (Board[start].isQueen == false) {
            if (Board[start].isWhite == true) {
                if (startRow % 2 == 0) {
                    if (startColumn == 0) {
                        // MOVER:
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow - 1 && endColumn == startColumn + 1) {
                            if (Board[(startRow - 1) * 4 + startColumn + 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            } // Checar Coluna  i e i + 1
                            // na Linha i-1
                            // COMER:
                        } else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn + 1].isWhite == false && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // Comer Para Tras:
                        else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn + 1].isWhite == false && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 1 || startColumn == 2) {
                        // MOVER
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow - 1 && endColumn == startColumn + 1) {
                            if (Board[(startRow - 1) * 4 + startColumn + 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } // COMER
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn].isWhite == false && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn + 1].isWhite == false && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn].isWhite == false && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn + 1].isWhite == false && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }

                    } else if (startColumn == 3) {
                        // MOVER
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                            // COMER
                        } else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn].isWhite == false && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn].isWhite == false && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                    }

                } else if (startRow % 2 == 1) {
                    if (startColumn == 0) {
                        // MOVER
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // Comer
                        else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn].isWhite == false && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        } // COMER PARA TRAS
                        else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn].isWhite == false && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 1 || startColumn == 2) {
                        // MOVER
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow - 1 && endColumn == startColumn - 1) {
                            if (Board[(startRow - 1) * 4 + startColumn - 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // COMER
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn - 1].isWhite == false && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn].isWhite == false && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn - 1].isWhite == false && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn].isWhite == false && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 3) {
                        // MOVER
                        if (endRow == startRow - 1 && endColumn == startColumn) {
                            if (Board[(startRow - 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow - 1 && endColumn == startColumn - 1) {
                            if (Board[(startRow - 1) * 4 + startColumn - 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // COMER
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn - 1].isWhite == false && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn - 1].isWhite == false && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                    }
                }
            } else if (Board[start].isWhite == false) // Se for peça preta SOMAR
            {
                if (startRow % 2 == 0) {
                    if (startColumn == 0) {
                        // MOVER:
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow + 1 && endColumn == startColumn + 1) {
                            if (Board[(startRow + 1) * 4 + startColumn + 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            } // Checar Coluna  i e i + 1
                            // na Linha i-1
                            // COMER:
                        } else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn + 1].isWhite == true && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn + 1].isWhite == true && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 1 || startColumn == 2) {
                        // MOVER
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow + 1 && endColumn == startColumn + 1) {
                            if (Board[(startRow + 1) * 4 + startColumn + 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } // COMER
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn].isWhite == true && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn + 1].isWhite == true && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn].isWhite == true && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn + 1].isWhite == true && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }

                    } else if (startColumn == 3) {
                        // MOVER
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                            // COMER
                        } else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn].isWhite == true && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn].isWhite == true && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        }
                    }

                } else if (startRow % 2 == 1) {
                    if (startColumn == 0) {
                        // MOVER
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // Comer
                        else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn].isWhite == true && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn].isWhite == true && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 1 || startColumn == 2) {
                        // MOVER
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow + 1 && endColumn == startColumn - 1) {
                            if (Board[(startRow + 1) * 4 + startColumn - 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // COMER
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn - 1].isWhite == true && Board[((startRow + 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow + 2 && endColumn == startColumn + 1 && Board[(startRow + 1) + endColumn + 1].isWhite == true && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn - 1].isWhite == true && Board[((startRow - 2) * 4) + startColumn - 1].isOccupied == false) {
                            code = 2;
                        } else if (endRow == startRow - 2 && endColumn == startColumn + 1 && Board[(startRow - 1) + endColumn + 1].isWhite == true && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    } else if (startColumn == 3) {
                        // MOVER
                        if (endRow == startRow + 1 && endColumn == startColumn) {
                            if (Board[(startRow + 1) * 4 + startColumn].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        } else if (endRow == startRow + 1 && endColumn == startColumn - 1) {
                            if (Board[(startRow + 1) * 4 + startColumn - 1].isOccupied) {
                                code = -1;
                            } else {
                                code = 1;
                            }
                        }
                        // COMER
                        else if (endRow == startRow + 2 && endColumn == startColumn - 1 && Board[(startRow + 1) + endColumn - 1].isWhite == true && Board[((startRow + 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                        // COMER PARA TRAS
                        else if (endRow == startRow - 2 && endColumn == startColumn - 1 && Board[(startRow - 1) + endColumn - 1].isWhite == true && Board[((startRow - 2) * 4) + startColumn + 1].isOccupied == false) {
                            code = 2;
                        }
                    }
                }
            }
        } else if (Board[start].isQueen == true) {
        }
    } else {
        code = 0;
    }

    return code;
};