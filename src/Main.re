let component = ReasonReact.statelessComponent("main");

let str = ReasonReact.string;


let make = (_children) => {
    ...component,
    render: (_self) => 
                    <div>
                        <TodoList />
                    </div>
};