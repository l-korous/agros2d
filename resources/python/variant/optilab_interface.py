from variant import ModelDict
from variant import ModelBase
from variant import ModelPostprocessor

_md = None

def _md_models(problem_dir):  
    global _md
    
    _md = ModelDict()
    _md.directory = problem_dir
    _md.load(ModelBase)
    
    lst = []
    for k, m in sorted(_md.dict.items()):
        lst.append({ 'key' : k, 'solved' : m.solved })
                
    return lst  
    
def _md_models_zip(filename):  
    global _md
    
    _md = ModelDict()
    _md.load_from_zip(filename)
    
    lst = []
    for k, m in sorted(_md.dict.items()):
        lst.append({ 'key' : k, 'solved' : m.solved })
                
    return lst      

def _md_postprocessor_variables():
    global _md

    mp = ModelPostprocessor(_md)
    keys = mp.variable_keys()
    #values = list(next(iter(_md.dict.values())).data.variables.values())
    #print(keys)
    #print(values)
    return mp.variable_keys()

def _md_postprocessor_values(variable):
    global _md

    mp = ModelPostprocessor(_md)
    return mp.variable(variable)
        
def _md_model(key):
    global _md
    
    return _md.dict[key]
    
def _open_in_agros2d(file_name):    
    import os.path    
    import sys; 
    sys.path.insert(0, os.path.abspath(os.path.join(file_name, os.pardir, os.pardir)))

    import problem
    p = problem.Model()
    p.load(file_name)
    p.create()
    
    return p
    
def _solve_in_agros2d(file_name):
    p = _open_in_agros2d(file_name)
    p.solve()
    p.save(file_name)