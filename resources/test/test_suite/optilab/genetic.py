import pythonlab

from test_suite.scenario import Agros2DTestCase
from test_suite.scenario import Agros2DTestResult

from variant.optimization import ContinuousParameter, Functionals, Functional
from variant.genetic import GeneticOptimization

class TestGenetic(Agros2DTestCase):
    def setUp(self):
        parameters = [ContinuousParameter('a', 0, 10),
                      ContinuousParameter('b', 0, 10),
                      ContinuousParameter('c', 0, 10),
                      ContinuousParameter('d', 0, 10),
                      ContinuousParameter('e', 0, 10)]

        functionals = Functionals([Functional("Func1", "max")])

        self.optimization = GeneticOptimization(parameters, functionals)
        self.optimization.directory = pythonlab.datadir('/resources/test/test_suite/optilab/genetic/solutions/')
        self.optimization.modelSetManager.solver = pythonlab.datadir('agros2d_solver')
        self.optimization.populationSize = 15

    def test_values(self):
        self.optimization.run(15, False)
        models = self.optimization.modelSetManager.load_all()
        max_value = 0.
        for model in models:
            value = model.variables["Func1"]
            if value > max_value:
                max_value = value
        self.interval_test("Maximum found by GA. Ssince there is random element in GA, this test may sometimes fail.", max_value, 45,50)


if __name__ == '__main__':
    import unittest as ut
    suite = ut.TestSuite()
    result = Agros2DTestResult()
    suite.addTest(ut.TestLoader().loadTestsFromTestCase(TestGenetic))
    suite.run(result)