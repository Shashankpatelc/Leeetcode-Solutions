class Spreadsheet:

    def __init__(self, rows: int):
        self.sheet = {}
        
    def setCell(self, cell: str, value: int) -> None:
        self.sheet[cell] = value

    def resetCell(self, cell: str) -> None:
        self.sheet[cell] = 0

    def getValue(self, formula: str) -> int:
        formula = formula[1:]
        opp = formula.split('+')
        if not opp[0].isdigit():
            opp[0] = self.sheet.get(opp[0], 0)
        else:
            opp[0] = int(opp[0])
        
        if not opp[1].isdigit():
            opp[1] = self.sheet.get(opp[1], 0)
        else:
            opp[1] = int(opp[1])
        return opp[0]+opp[1]
            
# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)