require './lib/binary_search_tree'

describe BinarySearchTree do 
    describe "#empty?" do
        it "Returns if the tree is empty or not" do
            tree = BinarySearchTree.new
            expect(tree.empty?).to eql(true)
        end
    end
end