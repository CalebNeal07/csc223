class BinarySearchTree 
    class Node
        def initialize(value, left, right)
            @value = value
            @left = left
            @right = right
        end
    end

    def initialize(values = nil)
        if values == nil 
            @value = nil
            return
        else 
            for value in values
                self.insert(value)
            end
        end
    end

    def empty?
        return @value == nil
    end
end
