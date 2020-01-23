'use strict';

//Child
class Checkbox extends React.Component {
    handleInputChange(event){
    }
    render() {
      return (
        <input 
        type="checkbox"
          onChange={(e) => this.props.onClick()}
          />
      );
    }
  }

  class Movement extends React.Component {
    constructor(props){
      super(props);
      this.state = {
        speedA: Array(5).fill(false)
      };
    }
      handleClick(i) {
        const speedA = this.state.speedA.slice();
        speedA[i] = !speedA[i];
        this.setState({speedA: speedA});
        console.log(speedA[i], i);
      }
    
      renderSquare(i) {
        return <Checkbox value={this.state.speedA[i]}
        onClick={()=>this.handleClick(i)}/>;
      }
      render(){
          return(
            <form id='movement-select'>
                <ul>
                    <label>Fly</label>{this.renderSquare(0)}
                    <br/>
                    <label>Walk</label>{this.renderSquare(1)}
                    <br/>
                    <label>Burrow</label>{this.renderSquare(2)}
                    <br/>
                    <label>Swim</label>{this.renderSquare(3)}
                    <br/>
                    <label>Climb</label>{this.renderSquare(4)}
                </ul>
            </form>
          )
      }
    }

ReactDOM.render(<Movement />, document.getElementById("movement-type-selector"));